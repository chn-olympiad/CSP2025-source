#include <bits/stdc++.h>
using namespace std;
char a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int u=0;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[++u]=s[i];
			for(int j=u-1;j>=1;j--){
				if(a[j]>a[j+1]){
					int t=a[j+1];
					a[j+1]=a[j];
					a[j]=t;
				}
				else{
					break;
				}
			}
		}
	}
	for(int i=u;i>=1;i--) cout<<a[i];
	return 0;
} 
