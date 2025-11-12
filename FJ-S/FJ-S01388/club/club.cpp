#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct stu{
	int x,y,z;
}a[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","r",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		int A=0,B=0,C=0,cnt1=0,cnt2=0,cnt3=0;
		scanf("%d",&n);
		int i,j;
		for(i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=3;j++){
				if(max({a[i].x,a[i].y,a[i].z})==a[i].x&&cnt1<(n/2)) A+=a[i].x,cnt1++;
				if(max({a[i].x,a[i].y,a[i].z})==a[i].y&&cnt2<(n/2)) B+=a[i].y,cnt2++;
				if(max({a[i].x,a[i].y,a[i].z})==a[i].z&&cnt3<(n/2)) C+=a[i].z,cnt3++;
			}
		}
		int sum=A+B+C;
		printf("%d\n",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
