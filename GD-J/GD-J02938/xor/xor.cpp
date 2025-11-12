#include<bits/stdc++.h>
using namespace std;
int a[500010],n,k;
long long s;
struct r_l{
	int l,r;
}cd[100100];
bool c(r_l x,r_l y){
	if(x.r>y.r){
		return 0;
	}
	return 1;
}
int main(){
	int num=1;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=i;j<=n;j++){
			s^=a[j];
			if(s==k){
				cd[num].l=i;
				cd[num].r=j;
				num++;
				break;
			}
		}
	}
	sort(cd+1,cd+num,c);
	s=1;
	int r_2=cd[1].r;
	for(int i=2;i<num;i++){
		if(cd[i].l>r_2){
			s++;
			r_2=cd[i].r;
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
