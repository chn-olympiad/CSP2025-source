#include <bits/stdc++.h>
using namespace std;
#define maxn 200000+10
string s1[maxn],s2[maxn];
string t1[maxn],t2[maxn];

string ss1[maxn],ss2[maxn];
string tt1[maxn],tt2[maxn];

int frs[maxn],frt[maxn];
int n,q;
int size;
/*
bool special_b=1;
bool special(){
	int b1_amount,b2_amount;
	
	for(int i=1;i<=n;i++){
		size=(int)s1[i].size();
		b2_amount=b1_amount=0;
		for(int j=0;j<size;j++){
			if(s1[i][j]!='a' && s1[i][j]!='b') return 0;
			if(s2[i][j]!='a' && s2[i][j]!='b') return 0;
			if(s1[i][j]=='b') b1_amount++;
			if(s2[i][j]=='b') b2_amount++;
		}
		if(b1_amount!=1 || b2_amount!=1) return 0;
	}
	for(int i=1;i<=q;i++){
		size=(int)t1[i].size();
		b2_amount=b1_amount=0;
		for(int j=0;j<size;j++){
			if(t1[i][j]!='a' && t1[i][j]!='b') return 0;
			if(t2[i][j]!='a' && t2[i][j]!='b') return 0;
			if(s1[i][j]=='b') b1_amount++;
			if(s2[i][j]=='b') b2_amount++;
		}
		if(b1_amount!=1 || b2_amount!=1) return 0;
	}
	return 1;
}*/
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++) cin>>t1[i]>>t2[i];
	
	/*special_b = special();
	if(special_b){
		map <int,bool> t;
		for(int i=1;i<=n;i++){
			int b1,b2;
			size=(int)s1[i].size();
			for(int j=0;j<size;j++){
				if(s1[j]=='b') b1=j;
				if(s2[j]=='b') b2=j;
			}
			map[abs(b1-b2)]=1;
		}
		for(int 
		return 0;
	}*/
	
	for(int i=1;i<=n;i++){
			int front=-1,last=0;
			size=(int)s1[i].size();
			for(int j=0;j<size;j++){
				if(s1[i][j]!=s2[i][j]){
					if(front==-1) front=j;
					last=j;
				}
			}
			//cout<<front<<" "<<last<<endl;
		    for(int j=front;j<=last;j++){
				ss1[i]+=s1[i][j];
				ss2[i]+=s2[i][j];
				
			}
			frs[i]=front;
	}
	for(int i=1;i<=q;i++){
			int front=-1,last=0;
			size=(int)t1[i].size();
			for(int j=0;j<size;j++){
				if(t1[i][j]!=t2[i][j]){
					if(front==-1) front=j;
					last=j;
				}
			}
		    for(int j=front;j<=last;j++){
				tt1[i]+=t1[i][j];
				tt2[i]+=t2[i][j];
				
			}
			frt[i]=front;
	}
	
	//a
	//for(int i=1;i<=n;i++) cout<<ss1[i]<<" "<<ss2[i]<<endl;
	//cout<<endl;
	//for(int i=1;i<=q;i++) cout<<tt1[i]<<" "<<tt2[i]<<endl;
	//cout<<endl;
	
	for(int j=1;j<=q;j++){ //t
		int ans=0;
		for(int i=1;i<=n;i++){ //s
			if(ss1[i]==tt1[j] && ss2[i]==tt2[j]){

				int z=frs[i];
				int a=frt[j]-z;
				int b=frs[i]-z;
				bool flag=1;
				
				//cout<<"A"<<frt[j]<<" "<<frs[i]<<endl;
				if(a<0) flag=0;
				size=(int)s1[i].size();
				int size2= (int) t1[j].size() ;
				while(flag && b < size){
					if(a >= size2) flag=0;
					if(t1[j][a]!=s1[i][b]) 
						flag=0;
					
					a++,b++;
				}
				if(flag) ans++;
			}
		}
		cout<<ans<<endl;
	}
	

	return 0;
}
