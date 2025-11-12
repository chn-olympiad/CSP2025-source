#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e3+5,M=2e3+5;

int n,q;
int s1len[N],s2len[N];
int t1len,t2len;
int nxt1[N][M],nxt2[N][M];
string s1[N],s2[N];
string t1,t2;


void build(){
	for(int k=1;k<=n;k++){
		s1[k]=s1[k]+'$';
//		cout<<s1[k]<<' '<<s2[k]<<endl<<s1len[k]<<' '<<s2len[k]<<endl;
		nxt1[k][1]=0;
		int i=2,j=1;
		while(i<=s1len[k]){
			if(s1[k][i]==s1[k][j]){
				nxt1[k][i++]=j++;
			}
			else if(j>1){
				j=nxt1[k][j-1]+1;
			}
			else nxt1[k][i++]=0;
		}
//		for(i=1;i<=s1len[k];i++) cout<<nxt1[k][i]<<' ';
//		cout<<endl;s1[k]=s1[k]+'$';

		s2[k]=s2[k]+'$';
		nxt2[k][1]=0;
		i=2,j=1;
		while(i<=s2len[k]){
			if(s2[k][i]==s2[k][j]){
				nxt2[k][i++]=j++;
			}
			else if(j>1){
				j=nxt2[k][j-1]+1;
			}
			else nxt2[k][i++]=0;
		}
//		cout<<s1[k]<<' '<<s2[k]<<endl<<s1len[k]<<' '<<s2len[k]<<endl;
	}
}

int ans;
vector<int>ans1,ans2;
void KMP(){
	ans=0;
	for(int k=1;k<=n;k++){
		
		int i=1,j=1;
		while(i<=t1len){
			if(t1[i]==s1[k][j]){
				i++;j++;
			}
			else if(j>1){
				j=nxt1[k][j-1]+1;
			}
			else i++;
			if(j>s1len[k]){
//				cout<<i-j+1<<endl;
				ans1.push_back(i-j+1);
			}
		}
//		cout<<endl;
		
		i=1,j=1;
		while(i<=t2len){
			if(t2[i]==s2[k][j]){
				i++;j++;
			}
			else if(j>1){
				j=nxt2[k][j-1]+1;
			}
			else i++;
			if(j>s2len[k]){
//				cout<<i-j+1<<endl;
				ans2.push_back(i-j+1);
			}
		}
//		cout<<endl;
		
		for(int i=0;i<ans1.size();i++){
			int x=ans1[i];
			int y=lower_bound(ans2.begin(),ans2.end(),x)-ans2.begin();
			if(x==ans2[y]&&ans1.size()==1&&ans2.size()==1) ans++;
		}
		ans1.clear();ans2.clear();
	}
	cout<<ans<<endl;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		s1len[i]=s1[i].size();s2len[i]=s2[i].size();
		s1[i]=' '+s1[i];s2[i]=' '+s2[i];
//		cout<<s1[i]<<' '<<s2[i]<<endl<<s1len[i]<<' '<<s2len[i]<<endl;

	}
	build();
	for(int i=1;i<=q;i++){	
		cin>>t1>>t2;
		t1len=t1.size();t2len=t2.size();
		if(t1len!=t2len){
			cout<<0<<endl;
			continue;
		}
		t1=' '+t1;t2=' '+t2;
		KMP();
	}
	
	return 0;
} 
