#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],sum;//^ÎªÒì»ò·ûºÅ 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int o=a[1];
	bool flag=true;
	for(int l=1,r=1;l<=n,r<=n;r++){
		if(flag){
			o=a[r];
			flag=false;
		}
		else{
			o^=a[r];
//			cout<<"r:"<<r<<" "<<a[r]<<endl;
		}
//		cout<<"o:"<<o<<endl;
		while(o>k){
			l++;
			o^=a[l];
		}
		if(o==k){
			sum++;
			l=r+1;
			r=l-1;
//			cout<<l<<" "<<r<<endl;
			o=0;
			flag=true;
		}
	}
	printf("%d",sum);
	return 0;
} 
