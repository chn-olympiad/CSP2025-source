#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		int cnt,a[100005],b[100005],c[100005],suma=0,sumb=0,sumc=0,ansa=0,ansb=0,ansc=0,ans;
		int mx[100005],ma=0,mb=0,mc=0,wa,wb,wc;
		bool t[100005];
		cin>>cnt;
		for(int i=1;i<=cnt;i++){
			t[i]=0;
		}
		for(int i=1;i<=cnt;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(cnt==2){
			int s1=max(max(max(a[1],b[1]),c[1]),max(max(a[2],b[2]),c[2]));
			cout<<s1;
		}
		else{
			for(int i=1;i<=cnt;i++){
				mx[i]=max(max(a[i],b[i]),c[i]);
			}
			for(int q=1;q<=cnt;q++){
				for(int i=1;i<=cnt;i++){
					if(ma<a[i]){
						wa=i;
						ma=a[i];
					}
				}
				for(int i=1;i<=cnt;i++){
					if(mb<b[i]){
						wb=i;
						mb=a[i];
					}
				}
				for(int i=1;i<=cnt;i++){
					if(mc<a[i]){
						wc=i;
						mc=a[i];
					}
				}
				
				
				
				int cnt1=cnt/2;
				if(ma==mx[wa]&&suma<=cnt1&&t[wa-q]==0){
					ansa+=ma;
					a[wa]=0;
					suma++;
					t[wa]=1;
					cout<<1<<endl;
				}
				if(mb==mx[wb]&&sumb<=cnt1&&t[wb-q]==0){
					ansb+=mb;
					b[wb]=0;
					sumb++;
					t[wb]=1;
					cout<<1<<endl;
				}
				if(mc==mx[wc]&&sumc<=cnt1&&t[wc-q]==0){
					ansc+=mc;
					sumc++;
					t[wc]=1;
					c[wc]=0;
					cout<<1<<endl;
				}
			}
			ans=ansa+ansb+ansc;
			cout<<ansa<<" "<<ansb<<" "<<ansc<<endl;
			cout<<ans<<endl;
		}
	}
	return 0;
}
