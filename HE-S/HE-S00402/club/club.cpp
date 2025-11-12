#include<fstream>
#include<algorithm>
using namespace std;
ifstream cin("club.in");
ofstream cout("club.out");
struct aaa{
	int a;
	int b;
	int c;
}d[10001];
struct bbb{
	int cha;
	int shu;
}flag[10001];
bool cmp(bbb x,bbb y){
	return x.cha<y.cha;
}
bool cmp1(aaa x,aaa y){
	return x.a<y.a;
}
bool cmp2(aaa x,aaa y){
	return x.b<y.b;
}
bool cmp3(aaa x,aaa y){
	return x.c<y.c;
}
long long t,n,book[11]={},sum,minn;
int main(){
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		sum=0;
		minn=0x7fffffff;
		for(int i=1;i<=3;i++){
			book[i]=0;
		}
		for(int i=1;i<=n;i++){
			flag[i].cha=0;
			flag[i].shu=0;
		}
		for(int i=1;i<=n;i++){
			cin>>d[i].a>>d[i].b>>d[i].c;
			if(d[i].a>=d[i].b&&d[i].a>=d[i].c){
				book[1]++;
			}
			else if(d[i].b>=d[i].a&&d[i].b>=d[i].c){
				book[2]++;
			}
			else{
				book[3]++;
			}
		}
		if(book[1]>n/2){
			for(int i=1;i<=n;i++){
				flag[i].cha=min(d[i].a-d[i].b,d[i].a-d[i].c);
				flag[i].shu=i;
			}
			sort(flag+1,flag+n+1,cmp);
			for(int i=1;i<=book[1]-n/2;i++){
				d[flag[i].shu].a=0;
			}
		}
		if(book[2]>n/2){
			for(int i=1;i<=n;i++){
				flag[i].cha=min(d[i].b-d[i].a,d[i].b-d[i].c);
				flag[i].shu=i;
			}
			sort(flag+1,flag+n+1,cmp);
			for(int i=1;i<=book[2]-n/2;i++){
				d[flag[i].shu].b=0;
			}
		}
		if(book[3]>n/2){
			for(int i=1;i<=n;i++){
				flag[i].cha=min(d[i].c-d[i].b,d[i].c-d[i].a);
				flag[i].shu=i;
			}
			sort(flag+1,flag+n+1,cmp);
			for(int i=1;i<=book[3]-n/2;i++){
				d[flag[i].shu].c=0;
			}
		}
		for(int i=1;i<=n;i++){
			if(d[i].a>=d[i].b&&d[i].a>=d[i].c){
				sum+=d[i].a;
			}
			else if(d[i].b>=d[i].a&&d[i].b>=d[i].c){
				sum+=d[i].b;
			}
			else{
				sum+=d[i].c;
			}
		}
		cout<<sum;
	}
	cin.close();
	cout.close(); 
	return 0;
}
