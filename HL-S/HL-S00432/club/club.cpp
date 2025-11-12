#include<bits/stdc++.h>
using namespace std;

int first(int a,int b,int c){
	if(a>=b&&a>=c) return a;
	if(b>=a&&b>=c) return b;
	return c;
}

int second(int a,int b,int c){
	int n=first(a,b,c);
	if(n==a) return max(b,c);
	if(n==b) return max(a,c);
	return max(a,b);
}
int a[100009][5],b[10009],s[10009];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d", &t);
	for(int o=1;o<=t;o++){
		int n;
		long long ret=0,flag=0;
		scanf("%d", &n);
		int c[]={0,0,0,0,0},tot=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d", &a[i][1],&a[i][2],&a[i][3]);
			if(first(a[i][1],a[i][2],a[i][3])==a[i][1]) b[i]=1,ret+=a[i][1],c[1]++;
			else if(first(a[i][1],a[i][2],a[i][3])==a[i][2]) b[i]=2,ret+=a[i][2],c[2]++;
			else if(first(a[i][1],a[i][2],a[i][3])==a[i][3]) b[i]=3,ret+=a[i][3],c[3]++;
		}
		for(int q=1;q<=3;q++){
			if(c[q]>n/2){
				for(int i=1;i<=n;i++){
					if(b[i]==q){
						tot++;
						s[tot]=first(a[i][1],a[i][2],a[i][3])-second(a[i][1],a[i][2],a[i][3]);
					}
				}
				sort(s+1,s+tot+1);
				int cnt=0;
				for(int i=1;i<=c[q]-n/2;i++){
					cnt+=s[i];
				}
				ret-=cnt;
				break;	
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}