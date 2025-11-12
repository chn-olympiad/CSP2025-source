#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,k;
int a[maxn];
struct node{
	int l,r,num;
};
node b[maxn];
void update(int l,int r){
//	cout<<l<<" "<<r<<endl;
	int flag=0;
	for(int i=l;i<=r;i++){
		if(b[i].num==1){
			flag=1;
			if(l<=b[i].l && r>=b[i].r){
				break;
			}else if(l<=b[i].l && r<=b[i].r){//ÓÒ¸²¸Ç 
				
			}else if(l>=b[i].l && r>=b[i].r){//×ó¸²¸Ç 
				
			}
		}
	}
	if(flag==0){
		for(int i=l;i<=r;i++){
			b[i].l=l;
			b[i].r=r;
			b[i].num=1;
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	int a=123^234;
//	int b=4^3;
//	int c=5^7;
//	
//	cout<<a<<" "<<b<<" "<<c;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=a[i];
		if(x==k){
			update(i,i);
		}
		for(int j=i+1;j<=n;j++){
//			cout<<i<<" "<<j<<" "<<x<<endl;
			x=x^a[j];
			if(x==k){
				update(i,j);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		cout<<b[i].l<<" "<<b[i].r<<" "<<b[i].num<<endl;
//	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(b[i].num){
			ans++;
			i=b[i].r+1;
		}
	}
	cout<<ans;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
