#include<bits/stdc++.h>
using namespace std;
int n,m,per,a[100005];
int s1,hao,hang=1,lie=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	per=n*m;
	for(int i=1;i<=per;i++) cin>>a[i];
	s1=a[1];
	sort(a+1,a+1+per,cmp);
	for(int i=1;i<=per;i++){
		if(a[i]==s1){
			hao=i;
			break;
		}
	}
	lie=hao/n;
	if(hao%n>0) lie++;
	hao=hao%n;
	if(hao!=0){
    	if(lie%2==0) hang=n-hao+1;
    	else hang=hao;
    }
    else{
    	if(lie%2==0) hang=1;
    	else hang=n;
	}
	cout<<lie<<" "<<hang;
	return 0;
}
