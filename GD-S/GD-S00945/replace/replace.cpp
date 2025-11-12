#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7; 
string a[N];
string b[N];
int ans;

void put(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x<10){
		putchar(x+'0');
	}else{
		put(x/10);
		putchar((x%10)+'0');
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--){
		ans=0;
		string s1,s2;
		cin>>s1>>s2;
		for(int i=1;i<=n;i++){
			int k=s1.find(a[i]);
			if(k!=-1){
				string l=s1;
				int len=b[i].length();
				for(int j=0;j<len;j++){
					l[j+k]=b[i][j];
				}
				if(l==s2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
