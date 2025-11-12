#include <bits/stdc++.h>
using namespace std;
int n,m,s[101],c=1,r=1,f=1;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>s[i];
	const int s1=s[1];
	if(n<=1&&m<=1){
		cout<<1<<" "<<1;
		return 0;
	}
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){//r行c列 n行m列
		if(s[i]==s1||r==n&&c==m) break;
		f=c%2;//奇数列下 偶数列上 
		if(f==1&&r+1<=n){
			r++;
			continue;
		}
		else if(f==0&&r-1>0){
			r--;
			continue;
		}
		if(r==n&&f==1||r==1&&f==0){
			c++;
			continue;
		}
	}
	cout<<c<<" "<<r<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
