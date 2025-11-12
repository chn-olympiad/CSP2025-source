#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10010

ll n,q;
int flag;
int a[MAXN];
string s1[MAXN];
string s2[MAXN];
string q1;
string q2;

void query(string q1,string q2){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sizeof(q1);j++){
			flag=0;
			if(q1[j]==s1[i][1]){
				for(int k=1;k<=sizeof(q1);k++){
					if(q1[j+k-1]!=q2[k]){
						flag=1;
						break;
					}
				}
				if(flag==1){
					continue;
				}
			}
			string x,y,z;
			for(int k=1;k<=j-1;k++){
				x[k]=q1[k];
			}
			for(int k=j+sizeof(q1)-1;k<=sizeof(s1);k++){
				y[i]=q1[k];
			}
			z=x+s1[i]+y;
			if(z==q2){
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
		cin>>q1>>q2;
		query(q1,q2);
	}
	return 0;
} 
