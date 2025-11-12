#include<bits/stdc++.h>
using namespace std;
int a[10];
int q=0;
int congzu(int x){
	int out,sum,beishu=1;
	for(int i=1;i<=q;i++){
		beishu=beishu*10;
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=1;j<=a[i];j++){
				sum=sum+i*beishu;
				beishu/=10;
			}
		}

	}
	return sum;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	int s;
	cin>>s;
	while(s!=0){
		a[s%10]++;
		q++;
		s=s/10;
	}
	cout<<congzu(q)/10;

}
