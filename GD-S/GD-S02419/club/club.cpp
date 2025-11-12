#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int a[100005],b[100005],c[100005];
	int num_a=0,num_b=0,num_c=0;
	int ma_a,ma_b,ma_c;
	int mi_a[100005],mi_b[100005],mi_c[100005];
	int xa=0,xb=0,xc=0,temp=30000;
	int dizhi;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		for(int i=0;i<n;i++){
			if(a[i]>=b[i]){
				if(a[i]>=c[i]){
					//cout<<"a"<<a[i]<<endl;
					num_a++;
					ma_a+=a[i];
					mi_a[xa]=a[i]-max(b[i],c[i]);
					xa++;
				}
				else{
					//cout<<"c"<<c[i]<<endl;
					num_c++;
					ma_c+=c[i];
					mi_c[xc]=c[i]-max(b[i],a[i]);
					xc++;
				}
			}
			else{
				if(b[i]>=c[i]){
					//cout<<"b"<<b[i]<<endl;
					num_b++;
					ma_b+=b[i];
					mi_b[xb]=b[i]-max(a[i],c[i]);
					xb++;
				}
				else{
					//cout<<"c"<<c[i]<<endl;
					num_c++;
					ma_c+=c[i];
					mi_c[xc]=c[i]-max(b[i],a[i]);
					xc++;
				}
			}
			if(num_b>n/2){
				for(int u=1;u<=num_b-(n/2);u++){
					for(int j=0;j<xb;j++){
						if(min(temp,mi_b[j])==mi_b[j]){
							temp=min(temp,mi_b[j]);
							dizhi=j;
						}
					}
					mi_b[dizhi]=30000;
					ma_b-=temp;
					temp=30000;
				}
			}
			if(num_a>n/2){
				for(int u=1;u<=num_a-(n/2);u++){
					for(int j=0;j<xa;j++){
						if(min(temp,mi_a[j])==mi_a[j]){
							temp=min(temp,mi_a[j]);
							dizhi=j;
						}
					}
					ma_a-=temp;
					mi_a[dizhi]=30000;
					temp=30000;
				}
			}
			if(num_c>n/2){
				for(int u=1;u<=num_c-(n/2);u++){
					for(int j=0;j<xc;j++){
						if(min(temp,mi_c[j])==mi_c[j]){
							temp=min(temp,mi_c[j]);
							dizhi=j;
						}
					}
					mi_c[dizhi]=30000;
					ma_c-=temp;
					temp=30000;
				}
			}
		}
		cout<<ma_a+ma_b+ma_c<<endl;
		num_a=0;
		num_b=0;
		num_c=0;
		ma_a=0;
		ma_b=0;
		ma_c=0;
		xa=0;
		xb=0;
		xc=0;
	}
	return 0;
} 
