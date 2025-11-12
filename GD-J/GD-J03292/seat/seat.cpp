#include<bits/stdc++.h>
using namespace std;
using LL = long long;

LL n,m,sco;
LL a[110];

bool cmp(LL x, LL y){
	return x > y;
}

int fun(LL x){
	LL l=1,r=m*n+1,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(a[mid]==x)return mid;
		if(a[mid]>x)l=mid+1;
		else r=mid-1;
	}
	return l;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin >> n >> m >> sco; //n行 m列 
	
	for(LL i=2;i<=n*m;i++)cin >> a[i];
	a[1]=sco;
	
	sort(a+1,a+n*m+1,cmp);
	
	LL id=fun(sco); //计算出他排第几位 
	LL tmp=0;
	
	for(LL i=0;i<m;i++){ //计算出人不在前面tmp列 
		if((i+1)*n >= id){
			tmp=i;
			break;
		}
	}
	
	if(tmp==0){  //说明肯定在第一列 
		cout << "1 " << id << '\n'; //直接输出在第几行 
		return 0;
	}
	else{ //计算他在第几行 
		LL dx = tmp+1,dy=0;
		LL tmp2=id-(tmp*n);
		if(dx%2==0){
			dy=n-tmp2+1;
		}else{
			dy=tmp2;
		}
		cout << dx << ' ' << dy << '\n';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

