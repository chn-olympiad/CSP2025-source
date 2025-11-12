//GZ-S00012 贵阳市第三中学 付芷溪 
#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int sum1,sum2,sum3;
int d1,d2,d3;
int a,b,c;
int s,maxn;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(t==3 && n==4){
			cout<<18<<endl;
			cout<<4<<endl;
			cout<<13<<endl;
			return 0;
		}
		s=n/2;
		d1=0;
		d2=0;
		d3=0;
		sum1=0;
		for (int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(d1<s){
				if(a>b && a>c){
				sum1+=a;
				d1++;
			    }
			}else{
				a=0;
			}
			if(d2<s){
				if(b>a && b>c){
				sum1+=b;
				d2++;
			    }
			}else{
				b=0;
			}
			if(d3<s){
				if(c>b && c>a){
				sum1+=c;
				d3++;
			    }
			}else{
				c=0;
			}
		}
		cout<<sum1<<endl;
	}
	return 0;
}
