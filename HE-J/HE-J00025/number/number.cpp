#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int m=n.size();
	int a[m+2];
	int b[m+2];
	memset(b,0,sizeof(b));
	if(m==1 && n>="0" && n<="9"){
		cout<<n;
	}
	else{
		int t=0;
		for(int i=0;i<=m-1;i++){
			if(n[i]>=0 && n[i]<=9){
				a[i]=n[i]-'0';
				t++;
			}
		}
		for(int i=0;i<=m-1;i++){
			cout<<a[i];
		}
		int maxn=0,s=t;
		while(t){
			for(int i=0;i<=s-1;i++){
				b[i]=1;
				if(a[i]>maxn && b[i]==0){
					maxn=a[i];
				}
				else{
					b[i]=0;
				}	
			}
			t--;
			cout<<maxn;
			maxn=0;
		}
	}
	return 0;
} 
