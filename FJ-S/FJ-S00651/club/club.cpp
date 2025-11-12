#include<bits/stdc++.h>
using namespace std;
struct p{
	int h;
	int x;
	int y;
	int z;
};
bool cmp1(p x,p y){
	return x.x>y.x;
}
bool cmp2(p x,p y){
	return x.y>y.y;
}
bool cmp3(p x,p y){
	return x.z>y.z;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	p a[10001];
	int n,t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		int s1=0,s2=0,s3=0,b1=0,b2=0,b3=0;
		for(int j=0;j<n;j++){
			a[i].h=i;
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x==max(max(a[i].x,a[i].y),a[i].z)){
				b1+=1;
				s1+=a[i].x;
			}
			if(a[i].y==max(max(a[i].x,a[i].y),a[i].z)){
				b2+=1;
				s2+=a[i].y;
			}
			if(a[i].z==max(max(a[i].x,a[i].y),a[i].z)){
				b3+=1;
				s3+=a[i].z;
			}
		}
		if((b1<=n/2)&&(b2<=n/2)&&(b3<=n/2)){
			cout<<s1+s2+s3<<endl;
			continue;
		}
		else{
			int ma=-1;
			if(b1>n/2){
				sort(a,a+n,cmp1);
				int d=b1-n/2,h=0;
				while(d){
					d-=1;
					s1-=a[h].x;
					if((a[h].y>a[h].z)&&(b2+1<=n/2)||(b3+1>n/2)){
						s2+=a[h].y;
					}
					else{
						s3+=a[h].z;
					}
					ma=max(ma,s1+s2+s3);
					h+=1;
				}
				sort(a,a+n,cmp2);
				h=0;
				while(d){
					d-=1;
					s1-=a[h].x;
					if((a[h].y>a[h].z)&&(b2+1<=n/2)||(b3+1>n/2)){
						s2+=a[h].y;
					}
					else{
						s3+=a[h].z;
					}
					ma=max(ma,s1+s2+s3);
					h+=1;
				}
				h=0;
				sort(a,a+n,cmp3);
				while(d){
					d-=1;
					s1-=a[h].x;
					if((a[h].y>a[h].z)&&(b2+1<=n/2)||(b3+1>n/2)){
						s2+=a[h].y;
					}
					else{
						s3+=a[h].z;
					}
					ma=max(ma,s1+s2+s3);
					h+=1;
				}
				cout<<ma<<endl;
				continue;
			}
			if(b2>n/2){
				sort(a,a+n,cmp1);
				int d=b2-n/2,h=0;
				while(d){
					d-=1;
					s2-=a[h].y;
					if((a[h].x>a[h].z)&&(b1+1<=n/2)||(b3+1>n/2)){
						s1+=a[h].y;
					}
					else{
						s3+=a[h].z;
					}
					ma=max(ma,s1+s2+s3);
					h+=1;
				}
				sort(a,a+n,cmp2);
				h=0;
				while(d){
					d-=1;
					s2-=a[h].y;
					if((a[h].x>a[h].z)&&(b1+1<=n/2)||(b3+1>n/2)){
						s1+=a[h].y;
					}
					else{
						s3+=a[h].z;
					}
					ma=max(ma,s1+s2+s3);
					h+=1;
				}
				sort(a,a+n,cmp3);
				h=0;
				while(d){
					d-=1;
					s2-=a[h].y;
					if((a[h].x>a[h].z)&&(b1+1<=n/2)||(b3+1>n/2)){
						s1+=a[h].y;
					}
					else{
						s3+=a[h].z;
					}
					ma=max(ma,s1+s2+s3);
					h+=1;
				}
				cout<<ma<<endl;
				continue;
			}
			if(b3>n/2){
				sort(a,a+n,cmp1);
				int d=b3-n/2,h=0;
				while(d){
					d-=1;
					s3-=a[h].z;
					if((a[h].x>a[h].y)&&(b1+1<=n/2)||(b2+1>n/2)){
						s1+=a[h].x;
					}
					else{
						s2+=a[h].y;
					}
					ma=max(ma,s1+s2+s3);
					h+=1;
				}
				sort(a,a+n,cmp2);
				h=0;
				while(d){
					d-=1;
					s3-=a[h].z;
					if((a[h].x>a[h].y)&&(b1+1<=n/2)||(b2+1>n/2)){
						s1+=a[h].x;
					}
					else{
						s2+=a[h].y;
					}
					ma=max(ma,s1+s2+s3);
					h+=1;
				}
				sort(a,a+n,cmp3);
				h=0;
				while(d){
					d-=1;
					s3-=a[h].z;
					if((a[h].x>a[h].y)&&(b1+1<=n/2)||(b2+1>n/2)){
						s1+=a[h].x;
					}
					else{
						s2+=a[h].y;
					}
					ma=max(ma,s1+s2+s3);
					h+=1;
				}
				cout<<ma<<endl;
				continue;
			}
		}
	}
	return 0;
}
