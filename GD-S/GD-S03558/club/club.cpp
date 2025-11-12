#include<bits/stdc++.h>
using namespace std;
int t,n,cb1,cb2,cb3;
struct mb{
	int x,y,z;
	char p;
};
mb a[100050];
long long ans;
bool cmp1(mb & c,mb & d){
	if(c.p != d.p){
		return c.p < d.p;
	}else{
		if(min(c.x-c.y,c.x-c.z) < min(d.x-d.y,d.x-d.z)){
			return 1;
		}else{
			return 0;
		}
	}
}
bool cmp2(mb & c,mb & d){
	if(c.p != d.p){
		if(c.p == '2'){
			return 0; 
		}else if(d.p == '2'){
			return 1;
		}else{
			return c.p < d.p;
		}
	}else{
		if(min(c.y-c.x,c.y-c.z) < min(d.y-d.x,d.y-d.z)){
			return 1;
		}else{
			return 0;
		}
	}
}
bool cmp3(mb & c,mb & d){
	if(c.p != d.p){
		return c.p > d.p;
	}else{
		if(min(c.z-c.x,c.z-c.y) < min(d.z-d.x,d.z-d.y)){
			return 1;
		}else{
			return 0;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cb1 = n/2;
		cb2 = n/2;
		cb3 = n/2;
		for(int i = 1;i <= n;i++){
			cin>>a[i].x >>a[i].y >>a[i].z ;
			if(a[i].x >= a[i].y && a[i].x >= a[i].z){
				a[i].p = '1';
				cb1--;
			}else if(a[i].y >= a[i].x && a[i].y >= a[i].z){
				a[i].p = '2';
				cb2--;
			}else{
				a[i].p = '3';
				cb3--;
			}
		}
		while(cb1<0 || cb2<0 || cb3<0){	
			int i = 1; 
			if(cb1 < 0){
				sort(a+1,a+n+1,cmp1);
				while(cb1 < 0){
					if(a[i].x-a[i].y < a[i].x-a[i].z){
						a[i].p = '2';
						cb1++;
						cb2--;
					}else{
						a[i].p = '3';
						cb1++;
						cb3--;
					}	
					i++;
				}				
			}
			if(cb2 < 0){
				sort(a+1,a+n+1,cmp2);
				while(cb2 < 0){
					if(a[i].y-a[i].x < a[i].y-a[i].z){
						a[i].p = '1';
						cb2++;
						cb1--;
					}else{
						a[i].p = '3';
						cb2++;
						cb3--;
					}	
					i++;
				}				
			}
			if(cb3 < 0){
				sort(a+1,a+n+1,cmp3);
				while(cb3 < 0){
					if(a[i].z-a[i].y < a[i].z-a[i].x){
						a[i].p = '2';
						cb3++;
						cb2--;
					}else{
						a[i].p = '1';
						cb3++;
						cb1--;
					}	
					i++;
				}
			}	
		}
		for(int i = 1;i <= n;i++){
			if(a[i].p == '1'){
				ans += a[i].x;
			}else if(a[i].p == '2'){
				ans += a[i].y;
			}else{
				ans += a[i].z;
			}
		}
		cout<<ans<<endl;
		ans = 0;
	}
	return 0;
}
