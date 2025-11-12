#include <iostream>
#include <algorithm>
using namespace std;
struct stu{
	int a;
	int b;
	int c;
	int m;
}k[100010];
struct node{
	bool c;
	bool j;
	int id;
}b[3];
bool cmp(stu x,stu y){
	return x.m>y.m;
}
int maxs(int a,int b,int c){
	return max(max(a,b),c);
}
bool bmp(node x,node y){
	if(x.j==y.j)
		return x.c;
	return x.j;
}
int mins(int a,int b,int c){
	return min(min(a,b),c);
}
bool wmp(stu x,stu y){
	return (x.m-mins(x.a,x.b,x.c))>(y.m-mins(y.a,y.b,y.c));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>k[i].a>>k[i].b>>k[i].c;
			k[i].m=maxs(k[i].a,k[i].b,k[i].c);
		}
		long long sum=0;
		for(int i=0;i<2;i++){
			if(i==0)
				sort(k,k+n,cmp);
			else
				sort(k,k+n,wmp);
			int pa=0,pb=0,pc=0;
			long long tmp=0;
			for(int i=0;i<n;i++){
				b[0].c=(k[i].m==k[i].a);
				b[0].j=(pa<n/2);
				b[1].c=(k[i].m==k[i].b);
				b[1].j=(pb<n/2);
				b[2].c=(k[i].m==k[i].c);
				b[2].j=(pc<n/2);
				for(int i=0;i<3;i++)
					b[i].id=i+1;
				sort(b,b+3,bmp);
				int chs=b[0].id;
				if(chs==1){
					pa++;
					tmp+=k[i].a;
				}
				else if(chs==2){
					pb++;
					tmp+=k[i].b;
				}
				else{
					pc++;
					tmp+=k[i].c;
				}
			}
			sum=max(sum,tmp);
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
