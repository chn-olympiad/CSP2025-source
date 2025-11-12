#include<bits/stdc++.h>
using namespace std;
int a[500005],n,m,num,cnt,b[500005],p,q;
int yihuo(int l,int r){
	if(l==r) return 0;
	int sum=a[l];
	for(int i = l+1;i <= r; i++){
		sum=sum^a[i];
	}
	return sum;
}
bool qwe(int l,int r){
	for(int i = l; i<=r;i++){
		if(b[i])return false;
	}
	return true;
}
int search(int l,int r){
	int w,i,sum=0;
	for(i = l; i<=r;i++){
		if(b[i]){
			w=b[i];
			p=i;
			break;
		}
	}
	while(w==b[i]){
		sum++;i++;
	}
	q=i;
	return sum;
}
int main(){ 
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n; i++)cin >> a[i];
	for(int i = 0;i < n; i++){
		for(int j = i;j < n; j++){
			if(m==yihuo(i,j)&&qwe(i,j)){
				num++;cnt++;
				for(int z=i;z<=j;z++)b[z]=cnt;
			}else if(m==yihuo(i,j)){
				if((j-i)<search(i,j)){
					for(int z=p;z<q;z++)b[z]=0;
					num++;cnt++;
					for(int z=i;z<=j;z++)b[z]=cnt;
				}
			}
		}
	}
	cout << num;
	return 0;
}
