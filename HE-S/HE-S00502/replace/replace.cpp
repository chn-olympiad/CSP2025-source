#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1e6;

vector<int> a[30],b[30];
int n,q,idx[30],cnt[30],sum;
string s1[MAX],s2[MAX];
string t1,t2;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
		int ppp=(int)(s1[i][0]-'a');
		b[ppp][cnt[ppp]++]=i;
	}
	while(q--){
		sum=0;
		for(int i=0;i<=29;i++)idx[i]=0;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		
		int x=0,y=0;
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i])x=i;
		}
		for(int i=t1.size()-1;i>=0;i--){
			if(t1[i]!=t2[i])y=i;
		}
		
		
		for(int i=0;i<t1.size();i++){
			a[t1[i]-'a'][idx[t1[i]-'a']++]=i;
		}
		
		for(int i=0;i<n;i++){
			for(int j=a[s1[i][0]-'a'][0];j<min(idx[s1[i][0]-'a'],x+1);j++){
				bool boo=0;
				if(j+s1[i].size()-1<y)continue;
				else{
					for(int k=0,q=j;k<s1[i].size();k++){
						if(s2[i][k]!=t2[j]){
							boo=1;
							break;
						}
					}
				}
				if(boo==0)sum++;
			}
		}
		cout<<sum<<"\n";
	}
	
	return 0;
}

