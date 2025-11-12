#include<bits/stdc++.h>
using namespace std;
int t,n;
struct f{
	int x,y,z,love;
}a[100005],c[100005];
int b[100005];
int cmp(f l,f r){
	if(l.love==r.love){
		if(l.love==1)return l.x+max(r.y,r.z)>r.x+max(l.y,l.z);
		else if(l.love==2)return l.y+max(r.x,r.z)>r.y+max(l.x,l.z);
		else return l.z+max(r.x,r.y)>r.z+max(l.x,l.y);
	}
	return l.love<r.love;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	while(t--){
		cin >>n;
	//	cout <<endl;
		for(int i=1;i<=n;i++){
			cin >>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>a[i].y&&a[i].x>a[i].z){
				a[i].love=1;
			}else if(a[i].y>a[i].z&&a[i].y>a[i].x){
				a[i].love=2;
			}else{
				a[i].love=3;
			}
		}
		sort(a+1,a+1+n,cmp);
		/*
		if(t!=1)continue;
	
		cout <<endl; 
		for(int i=1;i<=n;i++){
			cout <<i<<" "<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<" "<<a[i].love<<endl;
		}
	*/
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int j=0,n1=0,n2=0,n3=0,ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].love==1&&n1<n/2){
			//	cout <<1<<" "<<a[i].x<<endl;
				n1++;
				ans+=a[i].x;
				b[i]=1;
			}
			if(a[i].love==2&&n2<n/2){
			//	cout <<2<<" "<<a[i].y<<endl;
				n2++;
				ans+=a[i].y;
				b[i]=1;
			}
			if(a[i].love==3&&n3<n/2){
			//	cout <<3<<" "<<a[i].z<<endl;
				n3++;
				ans+=a[i].z;
				b[i]=1;
			}
			//cout <<b[i]<<endl;
			if(b[i]!=1){
				
				if(a[i].love==1){
					a[i].x=0;
					if(a[i].y>a[i].z)a[i].love=2;
					else a[i].love=3;
				}else if(a[i].love==2){
					a[i].y=0;
					if(a[i].x>a[i].z)a[i].love=1;
					else a[i].love=3;
				}else if(a[i].love==3){
					a[i].z=0;
					if(a[i].y>a[i].x)a[i].love=2;
					else a[i].love=1;
				}
				c[++j].x=a[i].x;
				c[j].y=a[i].y;
				c[j].z=a[i].z;
				c[j].love=a[i].love;
			}
		}
		/*
		for(int i=1;i<=j;i++){
			cout <<c[i].x<<" "<<c[i].y<<" "<<c[i].z<<" "<<c[i].love<<endl;
		}
		*/
		sort(c+1,c+1+j,cmp);
	/*
		cout <<endl <<j<<endl;
		for(int i=1;i<=j;i++){
			cout <<c[i].x<<" "<<c[i].y<<" "<<c[i].z<<" "<<c[i].love<<endl;
		}
		
		cout <<ans<<endl;
	*/
		for(int i=1;i<=n;i++){
			if(c[i].love==1){
				if(n1<n/2){
				// 	cout <<1<<" "<<c[i].x<<endl;
					n1++;
					ans+=c[i].x;
				}else if(n2<n/2){
					//cout <<2<<" "<<c[i].y<<endl;
					n2++;
					ans+=c[i].y;
				}else if(n3<n/2){
				//	cout <<3<<" "<<c[i].z<<endl;
					n3++;
					ans+=c[i].z;
				}
				continue;
			}else if(c[i].love==2){
				if(n2<n/2){
				//	cout <<2<<" "<<c[i].y<<endl;
					n2++;
					ans+=c[i].y;
				}else if(n1<n/2){
				//	cout <<1<<" "<<c[i].x<<endl;
					n1++;
					ans+=c[i].x;
				}else if(n3<n/2){
				//	cout <<3<<" "<<c[i].z<<endl;
					n3++;
					ans+=c[i].z;
				}
				continue;
			}else if(c[i].love==3){
				if(n3<n/2){
				//	cout <<3<<" "<<c[i].z<<endl;
					n3++;
					ans+=c[i].z;
				}else if(n1<n/2){
				//	cout <<1<<" "<<c[i].x<<endl;
					n1++;
					ans+=c[i].x;
				}else if(n2<n/2){
				//	cout <<2<<" "<<c[i].y<<endl;
					n2++;
					ans+=c[i].y;
				}
				continue;
			}
		}
		cout <<ans<<endl; 
	}
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
