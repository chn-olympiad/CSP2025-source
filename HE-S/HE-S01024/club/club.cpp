#include<bits/stdc++.h>
using namespace std;
long long t;

struct node{
	long long good1;
	long long good2;
	long long good3;
	int love;
	int love2;
	bool flag=1;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		long long n;
		cin>>n;
		node num[10005];
		long long a[10005];
		long long sum=0,sum1=0,sum2=0,sum3=0;
		bool be1=false;
		for(int j=1;j<=n;j++){
			cin>>num[j].good1>>num[j].good2>>num[j].good3;
			if (num[j].good1>num[j].good2 && num[j].good1>num[j].good3){
				num[j].love=num[j].good1;
				num[j].love2=max(num[j].good2,num[j].good3);
			}else if (num[j].good2>num[j].good1 && num[j].good2>num[j].good3){
				num[j].love=num[j].good2;
				num[j].love2=max(num[j].good1,num[j].good3);
			}else if (num[j].good3>num[j].good2 && num[j].good3>num[j].good1){
				num[j].love=num[j].good3;
				num[j].love2=max(num[j].good2,num[j].good1);
			}
			a[j]=num[j].love;
			if (num[j].love==num[j].good1){
				sum1+=1;
			}else if(num[j].love==num[j].good2){
				sum2+=1;
			}else if(num[j].love==num[j].good3){
				sum3+=1;
			}
		}
		if (sum1>n/2){
			be1=true;
			while(sum1>n/2){
				int lsi1=0;
				int m1=200005;
				for(int j=1;j<=n;j++){
					if (num[j].love-num[j].love2<m1 && num[j].flag==1){
						m1=num[j].love-num[j].love2;
						lsi1=j;
					}
				}
				if (num[lsi1].good2>num[lsi1].good3){
					a[lsi1]=num[lsi1].good2;
				}else{
					a[lsi1]=num[lsi1].good3;
				}
				sum1-=1;
				num[lsi1].flag=0;
			}
		}else if (sum2>n/2){
			while(sum2>n/2){
				int lsi2=0;
				int m2=200005;
				for(int j=1;j<=n;j++){
					if (num[j].love-num[j].love2<m2 && num[j].flag==1){
						m2=num[j].love-num[j].love2;
						lsi2=j;
					}
				}
				if (num[lsi2].good1>num[lsi2].good3){
					a[lsi2]=num[lsi2].good1;
				}else{
					a[lsi2]=num[lsi2].good3;
				}
				sum2-=1;
				num[lsi2].flag=0;
			}
		}
		else if (sum3>n/2){
			while(sum3>n/2){
				int lsi3=0;
				int m3=200005;
				for(int j=1;j<=n;j++){
					if (num[j].love-num[j].love2<m3 && num[j].flag==1){
						m3=num[j].love-num[j].love2;
						lsi3=j;
					}
				}
				if (num[lsi3].good2>num[lsi3].good1){
					a[lsi3]=num[lsi3].good2;
				}else{
					a[lsi3]=num[lsi3].good1;
				}
				sum3-=1;
				num[lsi3].flag=0;
			}
		}
		for(int j=1;j<=n;j++){
			sum+=a[j];
		}
		cout<<sum<<endl;
	}
	return 0;
} 
