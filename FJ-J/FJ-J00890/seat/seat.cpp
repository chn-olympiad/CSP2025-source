#include <bits/stdc++.h>
using namespace std;
long long ans,a[150],n,m,raa,rii;
int t=1,z;
bool cmp(int x,int y){
	return x>y;
}
//n 3 m 4
//i	  x  y  c
//1   1  1  100    x以1~n,n~1循环,第偶数个数组为 n~1 
//2	  2  1  99					  否则是1~n 
//*3   3  1  98
//4   3  2  97  1  y以每n个数后循环的数字加1 
//5   2  2  96	2 
//*6   1  2  95
//7   1  3  94
//8   2  3  96
//*9   3  3  95
//10  3  4  94
//11  2  4  93
//*12  1  4  92
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);//不欢迎雷老师看我的代码=) 
	scanf("%lld",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n*m;i++){
		scanf("%lld",&a[i]);
	}
	raa=a[1];
	sort(a+1,a+n*m+1,cmp);//排序 
//	for(int i=1;i<=n*m;i++) cout<<a[i];
	for(int i=1;i<=n*m;i++){//找小R的成绩下标 
		if(a[i]==raa){
			rii=i;
		}
	}
//	cout<<rii<<endl;
	if(rii%n==0) z=rii/n;
	else z=rii/n+1;
	if(rii%n>=1) cout<<(rii/n)+1<<' ';
	else cout<<rii/n<<' ';
	if(z%2==0){//判断是1~n或n~1 
		if(rii%n==0) cout<<1;
		else cout<<n-(rii%n)+1; 
	}else{
		if(rii%n==0) cout<<n;
		else cout<<rii%n;
	}

	return 0;
}
