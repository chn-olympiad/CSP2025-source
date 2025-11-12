#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=2e5+5,M=5e5+5;
LL n,q;
string s1[N],s2[N],t1,t2;
LL p1[M],p2[M],tp1,tp2;
void KMP1(string a,string b){
	string x='#'+a+b;
	int len=x.size();
	p1[1]=0;
	for(LL i=2;i<=len;i++){
		for(LL j=p1[i-1];;j=p1[j]){
			if(j*2>=i-1) continue;
			if(x[i]==x[j+1]){
				p1[i]=j+1;
				break;
			}
			if(j==0) break;
		}
	}
	
}
void KMP2(string a,string b){
	string x='#'+a+b;
	int len=x.size();
	p2[1]=0;
	for(int i=2;i<=len;i++){
		for(int j=p2[i-1];;j=p2[j]){
			if(j*2>=i-1) continue;
			if(x[i]==x[j+1]){
				p2[i]=j+1;
				break;
			}
			if(j==0) break;
		}
	}
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	int cnt;
	for(int i=1;i<=q;i++){
		cin>>t1>>t2;
		int lt=t1.size();
		if(lt!=t2.size()){
			cout<<"0\n";
			continue;
		}
		tp1=0,tp2=0;
		for(int k=lt-1;k>=0;k--){
			if(t1[k]!=t2[k]){
				if(tp1==0) tp1=k+1;
				tp2=k+1;
			}
		}
		//cout<<"t:"<<tp1<<" "<<tp2<<"\n";
		cnt=0;
		for(int k=1;k<=n;k++){
			int ls=s1[k].size();
			if(lt>=ls&&ls>=tp1-tp2+1){
				memset(p1,0,sizeof(p1));
				memset(p2,0,sizeof(p2));
				KMP1(s1[k],t1);
				KMP2(s2[k],t2);
				int len=s1[i].size()+t1.size();
			//for(int i=1;i<=len;i++) cout<<p1[i]<<" ";
			//cout<<"\n";
			//for(int i=1;i<=len;i++) cout<<p2[i]<<" ";
			//cout<<"\n";
			for(int i=1;i<=len;i++){
				if(p1[i]==p2[i]&&p1[i]==ls&&i-ls*2<=tp2) cnt++;
			}
			}
			
		}
		
		cout<<cnt<<"\n";
	}
	
	
	return 0;
} 
