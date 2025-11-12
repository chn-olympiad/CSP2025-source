#include<bits/stdc++.h>
using namespace std;
const int N=20010;
long long T;
long long n;
struct siz{
	long long a,b,c;
	long long num;
}sr[N],as[N];
long long find(){
	int ans=0;
	int a=0,b=0,c=0;
	for(int i=1;i<=n;i++){
		if(sr[i].a>=sr[i].b&&sr[i].a>=sr[i].c){
			ans+=sr[i].a;
			a++;
			as[i].num=sr[i].num;
			as[i].a=sr[i].a;
			as[i].b=as[i].a-as[i].num;
			as[i].c=1;
		}else if(sr[i].b>=sr[i].c){
			ans+=sr[i].b;
			b++;
			as[i].num=sr[i].num;
			as[i].a=sr[i].b;
			as[i].b=as[i].a-as[i].num;
			as[i].c=2;
		}else{
			ans+=sr[i].c;
			c++;
			as[i].num=sr[i].num;
			as[i].a=sr[i].c;
			as[i].b=as[i].a-as[i].num;
			as[i].c=3;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(as[i].num>as[j].num) swap(as[i],as[j]);
	if(a>n/2){
		int tmp=a;
		for(int i=1;i<=n;i++){
			if(as[i].c==1){
				ans-=as[i].num;
				tmp--;
			}
			if(tmp==n/2) break;
		}
	}else if(b>n/2){
		int tmp=b;
		for(int i=1;i<=n;i++){
			if(as[i].c==2){
				ans-=as[i].num;
				tmp--;
			}
			if(tmp==n/2) break;
		}
	}else if(c>n/2){
		int tmp=c;
		for(int i=1;i<=n;i++){
			if(as[i].c==3){
				ans-=as[i].num;
				tmp--;
			}
			if(tmp==n/2) break;
		}
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			long long x,y,z;
			cin>>x>>y>>z;
			sr[j].a=x,sr[j].b=y,sr[j].c=z;
			if(x>=y&&y>z) sr[j].num=x-y;
			else if(x>=y&&z>=x) sr[j].num=z-x;
			else if(z>=x&&y>=z) sr[j].num=y-z;
			else if(x>=z&&z>=y) sr[j].num=x-z;
			else if(y>=x&&x>=z) sr[j].num=y-x;
			else if(x<=y&&y<=z) sr[j].num=z-y;
		}
		cout<<find()<<endl;
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
