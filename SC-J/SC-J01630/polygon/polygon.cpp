#include<bits/stdc++.h>
using namespace std;
bool v[5010];
int a[5010];
int sum=0,n;
void o(int c,int ma,long long num){
	if(c!=0){
		for(int i=0;i<n;i++){
			if(v[i]!=1){
				v[i]=1;
				o(c-1,max(a[i],ma),num+a[i]);
				v[i]=0;
			}
			else{
				continue;
			}
		}
	}
	else{
		if(num>ma*2){
			sum++;
		}
		return ;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a+0,a+n);
	for(int c=3;c<=n;c++){
		for(int q=0;q<n-c;q++){
			v[q]=1;
			o(c-1,a[q],a[q]);
			v[q]=0;
		}
	}
	cout<<sum;
	return 0;
}

