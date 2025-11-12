#include<bits/stdc++.h>
using namespace std;
long long T,a,c,d,e,ans;
struct stu{
	int x,y,z,t,s;
}b[100001];
bool cmp(stu x,stu y){
	if(x.t==y.t){
		return x.s>y.s;
	}
	return x.t>y.t;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		long long s=0;
		cin>>a;
		c=d=e=0;
		for(int i=1;i<=a;i++){
			cin>>b[i].x>>b[i].y>>b[i].z;
			b[i].t=(max(b[i].x,max(b[i].y,b[i].z)));
			b[i].t=b[i].t-(b[i].x+b[i].y+b[i].z-b[i].t);
			b[i].s=b[i].x+b[i].y+b[i].z;
		}
		sort(b+1,b+1+a,cmp);
		for(int i=1;i<=a;i++){
//			cout<<b[i].x<<" "<<b[i].y<<" "<<b[i].z<<"\n";
			if(b[i].x==b[i].y&&b[i].x==b[i].z){
				if(c<d&&c<e){
					c++;
					s+=b[i].x;
				}
				else if(d<c&&d<e){
					d++;
					s+=b[i].y;
				}
				else if(e<d&&e<c){
					e++;
					s+=b[i].z;
				}
			}
			else if(b[i].x==b[i].y&&b[i].x>b[i].z){
				if(c<d&&(c+1)*2<=a){
					c++;
					s+=b[i].x;
				}
				else if(d<c&&(d+1)*2<=a){
					d++;
					s+=b[i].y;
				}
				else{
					e++;
					s+=b[i].z;
				}
			}
			else if(b[i].z==b[i].y&&b[i].z>b[i].x){
				if(e<d&&(e+1)*2<=a){
					e++;
					s+=b[i].z;
				}
				else if(d<e&&(d+1)*2<=a){
					d++;
					s+=b[i].y;
				}
				else{
					c++;
					s+=b[i].x;
				}
			}
			else if(b[i].x==b[i].z&&b[i].x>b[i].y){
				if(c<e&&(c+1)*2<=a){
					c++;
					s+=b[i].x;
				}
				else if(e<c&&(e+1)*2<=a){
					e++;
					s+=b[i].z;
				}
				else{
					d++;
					s+=b[i].y;
				}
			}
			else if(b[i].x>b[i].y&&b[i].x>b[i].z&&(c+1)*2<=a){
				c++;
				s+=b[i].x;
			}
			else if(b[i].y>b[i].x&&b[i].y>b[i].z&&(d+1)*2<=a){
				d++;
				s+=b[i].y;
			}
			else if(b[i].z>b[i].x&&b[i].z>b[i].y&&(e+1)*2<=a){
				e++;
				s+=b[i].z;
			}
			else if((b[i].x>b[i].y&&b[i].x<b[i].z||b[i].x>b[i].z&&b[i].x<b[i].y)&&(c+1)*2<a){
				c++;
				s+=b[i].x;
			}
			else if((b[i].y>b[i].x&&b[i].y<b[i].z||b[i].y>b[i].z&&b[i].y<b[i].x)&&(d+1)*2<a){
				d++;
				s+=b[i].y;
			}
			else if((b[i].z>b[i].y&&b[i].z<b[i].x||b[i].z>b[i].x&&b[i].z<b[i].y)&&(e+1)*2<a){
				e++;
				s+=b[i].x;
			}
			else if((c+1)*2<a){
				c++;
				s+=b[i].x;
			}
			else if((d+1)*2<a){
				d++;
				s+=b[i].y;
			}
			else{
				e++;
				s+=b[i].z;
			}
		}
		cout<<s<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
