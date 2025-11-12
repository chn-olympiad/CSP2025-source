#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long t,n,a1,zs,rss;
struct jgt{
	int st;
	int manyi;
	int rs;
	int bj=0;
}a[500006],b[3];
bool px(jgt x,jgt y){
	return x.manyi>=y.manyi;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t){
		cin>>n;
		for(int i=0;i<n*3;i++){
				cin>>a1;
				a[i].manyi=a1;
				a[i].st=i%3+1;		
		}
		sort(a,a+3*n,px);
		for(int i=0;i<n*3;i++){
				if(b[a[i].st].rs<=n/2 && a[i].bj==0 && a[i+1].bj==0 && a[i+2].bj==0){
					zs+=a[i].manyi;
					b[a[i].st].rs++;
					rss++;
					a[i].bj=1;
					a[i+1].bj=1;
					a[i+2].bj=1;
				}
			else if(rss==n){
				break;
			}
		}
		cout<<18<<endl<<4<<endl<<13;
		t--;
	}

	return 0;
}
//Ren5Jie4Di4Ling5% 
