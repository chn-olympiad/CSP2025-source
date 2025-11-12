#include<bits/stdc++.h>
using namespace std;
int t,n,m[4],b[100020],c[100020],d[100020],l;
struct s{
	int num;
	int x[4];
	int f;
}a[100020];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
	long long sum=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j].x[1]>>a[j].x[2]>>a[j].x[3];
			a[j].num=i;
				a[j].f=max(max(a[j].x[i],a[j].x[2]),a[j].x[3]);
				for(int k=1;k<=3;k++){
					if(a[j].f==a[j].x[k]&&n/2>m[k]){
						m[k]++;
						sum+=a[j].f;
					} 
				}
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
