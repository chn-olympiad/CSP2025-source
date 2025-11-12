#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z,c;
}a[100010];
int t;
bool cmp(node s1,node s2){
	if(s1.c==s2.c)return max(s1.x,max(s1.y,s1.z))>max(s2.x,max(s2.y,s2.z));
	return s1.c>s2.c;
}
void f(node w){
	if(w.x>=w.y && w.y>=w.z){
		w.c=(w.x-w.y);
	}
	else if(w.x>=w.z && w.z>=w.y){
		w.c=(w.x-w.z);
	}
	else if(w.y>=w.z && w.z>=w.x){
		w.c=(w.y-w.z);
	}
	else if(w.y>=w.x && w.x>=w.z){
		w.c=(w.y-w.x);
	}
	else if(w.z>=w.x && w.x>=w.y){
		w.c=(w.z-w.x);
	}
	else{
		w.c=(w.z-w.y);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].c=max(a[i].x,max(a[i].y,a[i].z))-min(a[i].x,min(a[i].y,a[i].z));
		}
		int k=n/2;
		sort(a+1,a+1+n,cmp);
		int b1=0,b2=0,b3=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i].x>=a[i].y && a[i].y>=a[i].z){
				if(b1<k){
				 	b1++;
					sum+=a[i].x;
				}
				else if(b2<k){
					b2++;
					sum+=a[i].y;
				}else{
					b3++;
					sum+=a[i].z;
				}
			}
			else if(a[i].x>=a[i].z && a[i].z>=a[i].y){
				if(b1<k){
				 	b1++;
					sum+=a[i].x;
				}
				else if(b3<k){
					b3++;
					sum+=a[i].z;
				}
				else{
					b2++;
					sum+=a[i].y;
				}
			}
			else if(a[i].y>=a[i].z && a[i].z>=a[i].x){
				if(b2<k){
				 	b2++;
					sum+=a[i].y;
				}
				else if(b3<k){
					b3++;
					sum+=a[i].z;
				}else{
					b1++;
					sum+=a[i].x;
				}
			}
			else if(a[i].y>=a[i].x && a[i].x>=a[i].z){
				if(b2<k){
				 	b2++;
					sum+=a[i].y;
				}
				else if(b1<k){
					b1++;
					sum+=a[i].x;
				}else{
					b3++;
					sum+=a[i].z;
				}
			}
			else if(a[i].z>=a[i].x && a[i].x>=a[i].y){
				if(b3<k){
				 	b3++;
					sum+=a[i].z;
				}
				else if(b1<k){
					b1++;
					sum+=a[i].x;
				}else{
					b2++;
					sum+=a[i].y;
				}
			}else{
				if(b3<k){
				 	b3++;
					sum+=a[i].z;
				}
				else if(b2<k){
					b2++;
					sum+=a[i].y;
				}else{
					b1++;
					sum+=a[i].x;
				}
			}
			//cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].z<<endl;
		}
		cout<<sum<<endl;
	}
	return 0;
}

