#include<bits/stdc++.h>
using namespace std;
int t;
struct Node{
	int a[4],fir,sec,cho,xjb;
}a[100010];
void f(){
	int n=0,sum=0,ch[5]={},a2=1,a3=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a[1]>>a[i].a[2]>>a[i].a[3];
		if(a[i].a[1]>=max(a[i].a[2],a[i].a[3])){
			a[i].fir=1;
		}else if(a[i].a[2]>=max(a[i].a[1],a[i].a[3])){
			a[i].fir=2;
		}else{
			a[i].fir=3;
		}
		if(a[i].a[1]<=max(a[i].a[2],a[i].a[3])&&a[i].a[1]>=min(a[i].a[2],a[i].a[3])){
			a[i].sec=1;
		}else if(a[i].a[2]<=max(a[i].a[1],a[i].a[3])&&a[i].a[2]>=min(a[i].a[1],a[i].a[3])){
			a[i].sec=2;
		}else{
			a[i].sec=3;
		}
		a[i].xjb=a[i].a[a[i].fir]-a[i].a[a[i].sec];
		a[i].cho=a[i].fir;
		ch[a[i].cho]++;
		sum+=a[i].a[a[i].cho];
		if(a[i].a[2]!=0){
			a2=0;
		}
		if(a[i].a[3]!=0){
			a3=0;
		}
	}
	for(int c=1;c<=3;c++){
		int minn=999999999,miin;
		while(ch[c]>n/2){
			for(int i=1;i<=n;i++){
				if(a[i].cho==c&&minn>a[i].xjb){
					minn=a[i].xjb;
					miin=i;
				}
			}
			
			//cout<<ch[1]<<" "<<ch[2]<<" "<<ch[3]<<" "<<n/2<<"\n";
			
			sum-=a[miin].xjb;
			ch[c]--;
			ch[a[miin].sec]++;
			a[miin].cho=a[miin].sec;
			a[miin].fir=a[miin].sec;
			
			
			if(a[miin].a[1]<=min(a[miin].a[2],a[miin].a[3])){
				a[miin].sec=1;
			}else if(a[miin].a[2]<=min(a[miin].a[1],a[miin].a[3])){
				a[miin].sec=2;
			}else{
				a[miin].sec=3;
			}
			a[miin].xjb=a[miin].a[a[miin].fir]-a[miin].a[a[miin].sec];
			
			
		}
	}
	cout<<sum;
	
	//cout<<" "<<ch[1]<<" "<<ch[2]<<" "<<ch[3]<<" "<<n/2;
	
	cout<<"\n";
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		f();
	}
	return 0;
}
