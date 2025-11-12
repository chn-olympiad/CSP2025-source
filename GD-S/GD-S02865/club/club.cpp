#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int a[10005],b[10005],c[10005],d[30005];
		int n,maxa=0,maxb=0,maxc=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>a[maxa]){
				maxa=i;
			}
			if(b[i]>b[maxb]){
				maxb=i;
			}
			if(c[i]>c[maxc]){
				maxc=i;
			}
		}
		int sum=a[maxa]+b[maxb]+c[maxc],dd=0;
		for(int i=0;i<n;i++){
			if(i!=maxa){
				d[dd]=a[i];
				dd++;
			}
		} 
		for(int i=0;i<n;i++){
			if(i!=maxb){
				d[dd]=b[i];
				dd++;
			}
		} 
		for(int i=0;i<n;i++){
			if(i!=maxc){
				d[dd]=c[i];
				dd++;
			}
		} 
		sort(d,d+n*3-3);
		sum+=d[n*3-4];
		cout<<sum;
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1

4
0 1 0
0 1 0
0 2 0
0 2 0

2
10 9 8
4 0 0
*/
