#include<bits/stdc++.h>
using namespace std;
int a[10011010];
int n,k;
int s=0;
int r_r=-1;
int g(int x,int y){
	int w_x[100010],w_y[100010];
	int w_2=0;
	while(x||y){
		w_x[w_2]=x%2;
		w_y[w_2]=y%2;
//	cout<<wx[w2]<<" "<<wy[w2]<<endl;
		x/=2;
		y/=2;
		w_2++;
	}
	int p[100010];//yihuohoushuzu
	for(int i=w_2-1;i>=0;i--){
		if(w_x[i]==w_y[i]){
			p[i]=0;
		}else{
			p[i]=1;
		}
	}
//	for(int i=0;i<w2;i++){
//		cout<<p[i]<<" ";
//	}cout<<endl;
	long long p_p=0;
	for(int i=w_2-1;i>=0;i--){
		if(p[i]==1){
			p_p+=(pow(2,i));
		}
	}
	return p_p;
}
int f(int l,int r){//qiuquan
	int q=a[l];
	for(int i=l+1;i<=r;i++){
		q=g(q,a[i]);//yihuo
	}
	return q;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	for(int i=0;i<n;i++){//i<=j
		for(int j=i;j<n;j++){
			if(f(i,j)==k&&(i>r_r)){
				s++;
				r_r=j;
			//	cout<<i<<" "<<j<<endl;
			}
		}
	}
	cout<<s;
	return 0;
}

