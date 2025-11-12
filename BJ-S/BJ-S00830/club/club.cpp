#include<bits/stdc++.h>
using namespace std;
struct node{
	int s1,s2,s3;
	int cha1,cha2;
	char cho;
}a[789178];
int middle(int a,int b,int c){
	if(a>=b&&b>=c) return b;
	if(c>=b&&b>=a) return b;
	if(a>=c&&c>=b) return c;
	if(c>=a&&a>=b) return a;
	if(b>=a&&a>=c) return a;
	if(b>=c&&c>=a) return c;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n,Achamin[114514],Bchamin[114514],Cchamin[114514],A=0,B=0,C=0,best=0;
		cin>>n;
		for(int i=1;i<=n/2;i++) Achamin[i]=789178910,Bchamin[i]=789178910,Cchamin[i]=789178910;
		for(int i=1;i<=n;i++){
			cin>>a[i].s1>>a[i].s2>>a[i].s3;
			int temp=max(a[i].s1,max(a[i].s2,a[i].s3));
			best+=temp;
			//cout<<"protect"<<best<<"before\n";
			if(temp==a[i].s1){
				for(int i=1;i<=n/2;i++){
					if(Achamin[i]>(temp-middle(a[i].s1,a[i].s2,a[i].s3))){
						for(int j=i;j<=n/2;j++){
							Achamin[i+1]=Achamin[i];
						}
						Achamin[i]=(temp-middle(a[i].s1,a[i].s2,a[i].s3));
						break;
					}
				}
				A++;
			}
			if(temp==a[i].s2){
				for(int i=1;i<=n/2;i++){
					if(Bchamin[i]>(temp-middle(a[i].s1,a[i].s2,a[i].s3))){
						for(int j=i;j<=n/2;j++){
							Bchamin[i+1]=Bchamin[i];
						}
						Bchamin[i]=(temp-middle(a[i].s1,a[i].s2,a[i].s3));
						break;
					}
				}
				B++;
			}
			if(temp==a[i].s3){
				for(int i=1;i<=n/2;i++){
					if(Cchamin[i]>(temp-middle(a[i].s1,a[i].s2,a[i].s3))){
						for(int j=i;j<=n/2;j++){
							Cchamin[i+1]=Cchamin[i];
						}
						Cchamin[i]=(temp-middle(a[i].s1,a[i].s2,a[i].s3));
						break;
					}
				}
				C++;
			}
		}
		if(A>(n/2)){
			int k=A-(n/2);
			int sum=0;
			for(int i=1;i<=k;i++) sum+=Achamin[i];
			best-=sum;
		}
		if(B>(n/2)){
			int k=B-(n/2);
			int sum=0;
			for(int i=1;i<=k;i++) sum+=Bchamin[i];
			best-=sum;
		}
		if(C>(n/2)){
			int k=C-(n/2);
			int sum=0;
			for(int i=1;i<=k;i++) sum+=Cchamin[i];
			best-=sum;
		}
		cout<<best<<"\n";
	}
	return 0;
}
//RP+=INF
			
