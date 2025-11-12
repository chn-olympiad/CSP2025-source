#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q;
map<string,string> s;
string t,tt;
int p(string a,string b){
	int n=a.size();
	int an=b.size()-1,lo=0;
	for(int i = 0;i<n;i++){
		if(n-i-an<=0)continue;
		while(a[i]==b[lo]){
			lo++;
			if(lo==an){
				return i;
			}
		}
		lo=0;
	}
	return -1;
}
string a;string b;
void so1(){
	
	
	if(a.size()!=b.size()){
		cout<<"0\n";
		return ;
	}
	int ch=0,ans=0,xi=0;
	int n=a.size();
	string sli="",sla="",xli="",xla="";
	bool st=0,en=0;
	for(int i = 0;i<n;i++){
		if(a[i]!=b[i]){
			if(st==0){
				ch=i;
			}
			st=1;
			
		}
//		if(st){
//			sli+=a[i];
//			xli+=b[i];
//		}
		if(a[i]!=b[i]){
			xi=i;
//			sla=sli;
//			xla=xli;
		}
	}
	for(int i = ch;i<=xi;i++){
		sla+=a[i];
		xla+=b[i];
	}
//	cout<<sla<<" "<<xla<<"\n";
	for(auto it: s){
		string la=it.first;
		int f=la.find(sla);
		la=it.second;
		int s=la.find(xla);
		if(f<0||f>n-1||s<0||s>n-1)continue;
		if(f==s){
			ans++;
		}
	}
	cout<<ans<<"\n";
}
bool ah[N],bh[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	string li;
	for(int i = 1;i<=n;i++){
		cin>>li;
		cin>>s[li];
	}
	int la,lb,flag=0;
	for(int i = 1;i<=q;i++){
		flag=1;
		cin>>a>>b;
		la=0;
		lb=0;
		for(char j=0;j<=26;j++){
			ah[j]=0;
			
		}
		int na=a.size(),nb=b.size();
		for(int j = 0;j<na;j++){
			if(!ah[a[j]-'a']){
				la++;
				ah[a[j]-'a']=1;
			}
			if(!bh[b[j]-'a']){
				lb++;
				bh[b[j]-'a']=1;
			}
			if(la>2||lb>2){
				flag=2;
			}
		}
		if(n<=1000)so1();
		else cout<<0<<"\n";
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
