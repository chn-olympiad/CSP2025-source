#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[5];
int maxa(int a,int b,int c){
	if(a>=b and a>=c){
		return 1;
	}else if(b>=a and b>=c){
		return 2;
	}else if(c>=a and c>=b){
		return 3;
	}
}
int maxa1(int a,int b,int c){
	if(a>=b and a<=c){
		return 1;
	}else if(b>=a and b<=c){
		return 2;
	}else if(c>=a and c<=b){
		return 3;
	}
}
int maxa2(int a,int b,int c){
	if(a<=b and a<=c){
		return 1;
	}else if(b<=a and b<=c){
		return 2;
	}else if(c<=a and c<=b){
		return 3;
	}
}
bool flag=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int num[6]={0};
	for(int j=1;j<=t;j++){
		flag=0;
		cin>>n;
		int b[5]={0};
		for(int i=1;i<=n;i++){
			cin>>a[1]>>a[2]>>a[3];
			int q=n/2;
			if(maxa(a[1],a[2],a[3])==1){
				if(b[1]<=q){
					b[1]++;
					num[j]+=a[1];
					flag=1;
				}
			}else if(maxa(a[1],a[2],a[3])==2){
				if(b[2]<=q){
					b[2]++;
					num[j]+=a[2];
					flag=1;
				}
			}else{
				if(b[3]<=q){
					b[3]++;
					num[j]+=a[3];
					flag=1;
				}
			}
			if(flag==0){
				if(maxa1(a[1],a[2],a[3])==1){
					if(b[1]<=q){
						b[1]++;
						num[j]+=a[1];
						flag=1;
					}
				}else if(maxa1(a[1],a[2],a[3])==2){
					if(b[2]<=q){
						b[2]++;
						num[j]+=a[2];
						flag=1;
					}
				}else{
					if(b[3]<=q){
						b[3]++;
						num[j]+=a[3];
						flag=1;
					}
				}
			}
			else if(flag==0){
				if(maxa2(a[1],a[2],a[3])==1){
					if(b[1]<=q){
						b[1]++;
						num[j]+=a[1];
						flag=1;
					}
				}else if(maxa2(a[1],a[2],a[3])==2){
					if(b[2]<=q){
						b[2]++;
						num[j]+=a[2];
						flag=1;
					}
				}else{
					if(b[3]<=q){
						b[3]++;
						num[j]+=a[3];
						flag=1;
					}
				}
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}
