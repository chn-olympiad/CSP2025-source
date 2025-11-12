#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct dgs{
	int a,b,c;
	int mmax,mmax2;
}l[1000005];
int t,n,w2,w3,w4;
long long sum=0;
bool cmp(dgs x,dgs y){
	return x.mmax-x.mmax2>y.mmax-y.mmax2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int h=1;h<=t;h++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>l[j].a>>l[j].b>>l[j].c;
			l[j].mmax=max(l[j].c,max(l[j].a,l[j].b));
			if(l[j].mmax==l[j].c){
				l[j].mmax2=max(l[j].a,l[j].b);
			}
			if(l[j].mmax==l[j].b){
				l[j].mmax2=max(l[j].a,l[j].c);
			}
			if(l[j].mmax==l[j].a){
				l[j].mmax2=max(l[j].c,l[j].b);
			}
		}
		sort(l+1,l+n+1,cmp);
		for(int j=1;j<=n;j++){
			if(l[j].mmax==l[j].a){
				if(w2<n/2){
					w2++;
					sum+=l[j].mmax;
				}else{
					if(l[j].mmax2==l[j].b){
						if(w3<n/2){
							w3++;
							sum+=l[j].mmax2;
						}else{
							w4++;
							sum+=l[j].c;
						}
					}else{
						if(w4<n/2){
							w4++;
							sum+=l[j].mmax2;
						}else{
							w3++;
							sum+=l[j].b;
						}
					}
				}
			}else if(l[j].mmax==l[j].b){
				if(w3<n/2){
					w3++;
					sum+=l[j].mmax;
				}else{
					if(l[j].mmax2==l[j].a){
						if(w2<n/2){
							w2++;
							sum+=l[j].mmax2;
						}else{
							w4++;
							sum+=l[j].c;
						}
					}else{
						if(w4<n/2){
							w4++;
							sum+=l[j].mmax2;
						}else{
							w2++;
							sum+=l[j].a;
						}
					}
				}
			}else{
				if(w4<n/2){
					w4++;
					sum+=l[j].mmax;
				}else{
					if(l[j].mmax2==l[j].b){
						if(w3<n/2){
							w3++;
							sum+=l[j].mmax2;
						}else{
							w2++;
							sum+=l[j].a;
						}
					}else{
						if(w2<n/2){
							w2++;
							sum+=l[j].mmax2;
						}else{
							w3++;
							sum+=l[j].b;
						}
					}
				}
			}
		}
		cout<<sum<<endl;
		sum=0;
		w2=0;
		w3=0;
		w4=0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

