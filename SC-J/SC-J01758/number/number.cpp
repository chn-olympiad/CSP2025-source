#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string a;
int f[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i=0,cnt=0;
	cin>>a;
	while(a[i]>0){
		
		if(a[i]<='9'&&a[i]>='0'){
			f[++cnt]=a[i]-'0';
		}i++;
	}sort(f+1,f+cnt+1);
	for(int i=cnt;i>=1;i--) cout<<f[i]; 
	return 0;
}

