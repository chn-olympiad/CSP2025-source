#include<bits/stdc++.h>
using namespace std;
int c,r,a[105],cnt,flag,mod;
bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>c>>r;
	int n = c*r;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int x = a[1];
	sort(a+1,a+n+1,cmp);
	int l = 1,r = n;
	while(l<=r){
		int mid = (l+r)/2;
		if(a[mid]==x){
			cnt = mid;
			break;
		}
		else if(a[mid]>x){
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}
	if(cnt<=c){
		cout<<1<<" "<<cnt;
		return 0;
	}else{
		flag = 0;
		mod = cnt%c;
		if(mod==0){
			flag = cnt/c;
		}
		else{
			flag = cnt/c;
			flag++;
		}
	}
	if(flag%2!=0){
		cout<<flag<<" "<<mod;
		return 0;
	}
	else{
		cout<<flag<<" "<<(c-mod+1);
	}
	return 0;
}
