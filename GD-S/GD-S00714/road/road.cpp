#include<bits/stdc++.h>
using namespace std;
struct node{
	int zu;
	int ju;
	int o3;
	int o2;
}o1[100005];
int cmp(node x,node y){
	return x.o3>y.o3;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int x;
	cin>>x;
	while(x--){
		long long ans=0;
		int n;
		cin>>n;
		int mid=n/2;
		int ac=0,bc=0,cc=0;
		for(int i=0;i<n;i++){
			int t=0;
			int a,b,c;
			cin>>a>>b>>c;
			if(a>=b&&a>=c){
				o1[i].ju=a;
				o1[i].zu=1;
				if(b>=c){
					o1[i].o2=b;
				}else{
					o1[i].o2=c;
				}                 
				o1[i].o3=o1[i].ju-o1[i].o2;
			}if(b>=c&&b>=a){
				o1[i].ju=b;
				o1[i].zu=2;
				if(a>=c){
					o1[i].o2=a;
				}else{
					o1[i].o2=c;
				} 
				o1[i].o3=o1[i].ju-o1[i].o2;
			}if(c>=b&&c>=a){
				o1[i].ju=c;
				o1[i].zu=3;
				if(b>=a){
					o1[i].o2=b;
				}else{
					o1[i].o2=a;
				} 
				o1[i].o3=o1[i].ju-o1[i].o2;
			}
		}
		sort(o1,o1+n,cmp);
		for(int i=0;i<n;i++){
			if(o1[i].zu==1){
				if(ac<mid){
					ac++;
					ans+=o1[i].ju;
				}else{
					ans+=o1[i].o2; 
				}
			}if(o1[i].zu==2){
				if(bc<mid){
					bc++;
					ans+=o1[i].ju;
				}else{
					ans+=o1[i].o2;
				}
			}if(o1[i].zu==3){
				if(cc<mid){
					cc++;
					ans+=o1[i].ju;
				}else{
					ans+=o1[i].o2;
				}
			}
		} 
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
