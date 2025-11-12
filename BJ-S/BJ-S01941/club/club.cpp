#include<iostream>
using namespace std;
long long n,x,y,z,b[4],maxsum,c123,c12,c13,c23;
struct st{
	int one,two,three,p1,p2,p3;
	bool b12,b23,b13,b123;
};
struct st a[100001];
int main(){
	freopen("club.in","r","stdin");
	freopen("club.out","w","stdout");
	int T;
	cin>>T;
	for(int p=1;p<=T;p++){
		cin>>n;
		maxsum=0,c12=0,c13=0,c23=0,c123=0;
		if(n==2){
			for(int i=1;i<=n;i++){
				cin>>x>>y>>z;
				if(x>=y&&x>=z) a[i].one=x,a[i].p1=1;
				else if(y>=z&&y>=x) a[i].one=y,a[i].p1=2;
				else if(z>=x&&z>=y) a[i].one=z,a[i].p1=3;
				
				if(x>=y&&x<=z) a[i].two=x,a[i].p2=1;
				else if(y>=z&&y<=x) a[i].two=y,a[i].p2=2;
				else if(z>=x&&z<=y) a[i].two=z,a[i].p2=3;
				if(x<=y&&x>=z) a[i].two=x,a[i].p2=1;
				else if(y>=x&&y<=z) a[i].two=y,a[i].p2=2;
				else if(z>=y&&z<=x) a[i].two=z,a[i].p2=3;
				
				if(x<=y&&x<=z) a[i].three=x,a[i].p3=1;
				else if(y<=x&&y<=z) a[i].three=y,a[i].p3=2;
				else if(z<=x&&z<=y) a[i].three=z,a[i].p3=3;
				if(a[i].one==a[i].two&&a[i].one==a[i].three) a[i].b123=true,c123++;
				else if(a[i].one==a[i].two) a[i].b12=true,c12++;
				else if(a[i].one==a[i].three) a[i].b13=true,c13++;
				else if(a[i].two==a[i].three) a[i].b23=true,c23++;
			}
			if(a[1].p1!=a[2].p1) cout<<a[1].one+a[2].one;
			else{
				if(a[1].b12==true||a[1].b123==true||a[1].b13==true||a[2].b12==true||a[2].b123==true||a[2].b13==true) cout<<a[1].one+a[2].one;
				else cout<<max(a[1].one+a[2].two,a[1].two+a[2].one)<<endl;
			}
		}else{
			for(int i=1;i<=n;i++){
				cin>>x>>y>>z;
				maxsum+=max(x,max(y,z));
			}
			cout<<maxsum<<endl;
		}
	}
	return 0;
}

