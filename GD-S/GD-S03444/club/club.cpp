#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long T,n,sum;
int x[N],y[N],z[N],g[5];
struct ac{
	int st;
	int nd;
	int rd;
	int id;
	int maxa;
	int id2;
}a[N];
int cmp(ac x,ac y){
	if(x.maxa!=y.maxa){
		return x.maxa>y.maxa;
	}
	return x.nd>y.nd;
}
int answer(){
	if(g[2]==n/2||g[3]==n/2){
		return 0;
	}
	return 1;
}
int p(ac x,ac y){
	return x.rd>y.rd;
}
int q(ac x,ac y){
	return x.nd>y.nd;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T>0){
		T--;
		cin>>n;
		sum=0;
		memset(g,0,sizeof(g));
		for(int i=1;i<=n;i++){
			cin>>x[i]>>y[i]>>z[i];
			a[i].id=i;
			a[i].st=0,a[i].nd=y[i]-x[i],a[i].rd=z[i]-x[i];
			if(a[i].nd>=a[i].rd){
				a[i].maxa=a[i].nd;
				a[i].id2=2;
			}
			if(a[i].rd>a[i].nd){
				a[i].maxa=a[i].rd;
				a[i].id2=3;
			}
			sum+=x[i];
		}
		g[1]=n;
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(a[i].maxa<0&&g[1]<=n/2){
				cout<<sum<<endl;
				break;
			}
			sum+=a[i].maxa;
			g[1]--,g[a[i].id2]++;
			if(answer()==0){
				if(g[2]==n/2){
					sort(a+i+2,a+1+n,p);
					for(int j=i+1;j<=n;j++){
						if(a[j].rd<0){
							break;
						}
						sum+=a[j].rd;
						g[1]--,g[3]++;
						if(g[3]==n/2){
							break;
						}
					}
					cout<<sum<<endl;
				}
				else if(g[3]==n/2){
					sort(a+i+2,a+1+n,q);
					for(int j=i+1;j<=n;j++){
						if(a[j].nd<0){
							break;
						}
						sum+=a[j].nd;
						g[1]--,g[2]++;
						if(g[2]==n/2){
							break;
						}
					}
					cout<<sum<<endl;
				}
				break;
			}
		}
	}
	return 0;
}

