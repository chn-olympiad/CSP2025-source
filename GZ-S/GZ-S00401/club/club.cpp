//GZ-S00401 贵阳市花溪区同为京学附属实验学校 袁家绎
#include<bits/stdc++.h>
using namespace std;
struct person{
	int b1,b2,b3;
	int ttt;
};
int b[3];
person a[100099],b1[100099],c[100099];
bool cmp(person x,person y){
	return x.b1>y.b1;
}
bool cmp1(person x,person y){
	return x.b2>y.b2;
}
bool cmp2(person x,person y){
	return x.b3>y.b3;
}
bool cmpsp(person x,person y){
	return (x.b1-x.b2)<(y.b1-y.b2);
}
bool cmpsp1(person x,person y){
	return (x.b2-x.b3)<(y.b2-y.b3);
}
int main(){
	freopen("club5.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int t=0;
	cin>>t;


	while(t--){
		for(int i=0;i<100099;i++){
			b1[i].b1=0;b1[i].b2=0;b1[i].b3=0;
			a[i].b1=0;a[i].b2=0;a[i].b3=0;
			c[i].b1=0;c[i].b2=0;c[i].b3=0;
		}
		b[0]=0;b[1]=0;b[2]=0;
		long long allprise=0;
		int n=0;
		cin>>n;
		person p[n];
		for(int i=0;i<n;i++){
			cin>>p[i].b1>>p[i].b2>>p[i].b3;
			p[i].ttt=0;
		}
		sort(p,p+n,cmp);
		for(int i=0;i<n;i++){
			if(p[i].b1>p[i].b3&&p[i].b1>p[i].b2){
				b[0]++;
				p[i].ttt=1;
				a[i]=p[i];
			}
		}
		sort(p,p+n,cmp1);
		for(int i=0;i<n;i++){
			if(p[i].b2>p[i].b3&&p[i].b2!=0&&p[i].ttt==0){
				b[1]++;
				p[i].ttt=2;
				b1[i]=p[i];
			}
		}
		sort(p,p+n,cmp2);
		for(int i=0;i<n;i++){
			if(p[i].b3!=0&&p[i].ttt==0){
				b[2]++;
				p[i].ttt=3;
				c[i]=p[i];
			}
		}
		int i=0;
		if(b[0]>n/2){
			sort(a,a+b[0],cmpsp);

			while(b[0]>n/2){
				i++;
				b[0]--;
				b[1]++;
				b1[b[1]]=a[i-1];
				a[i-1].b1=0;a[i-1].b2=0;a[i-1].b3=0;
			}

		}
		for(int o=0;o<n;o++){
				 allprise+=a[o].b1;
			}
		int j=0;
		if(b[1]>n/2){
			sort(b1,b1+b[1],cmpsp1);

			while(b[1]>n/2){
				j++;
				b[1]--;
				b[2]++;
				c[b[2]]=b1[j-1];
				b1[j-1].b1=0;b1[j-1].b2=0;b1[j-1].b3=0;
			}

		}
		for(int o=0;o<n;o++){
				 allprise+=b1[o].b2;
			}
		sort(c,c+n/2,cmp2);
		for(int o=0;o<n;o++){
				 allprise+=c[o].b3;
			}
		cout<<allprise<<endl;
	}
	return 0;
}
