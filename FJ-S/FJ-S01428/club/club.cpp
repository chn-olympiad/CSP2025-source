//club.cpp
#include<iostream>
#include<algorithm>
struct like{
	int a,b,c,max;
}person[int(5e5)];
using namespace std;
bool cmp(like a,like b){
	if(a.max==b.max) return min(a.a,min(a.b,a.c))>min(b.a,min(b.b,b.c));
	return a.max>b.max;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,i,j,a=0,b=0,c=0,tmp,sum=0;
	cin>>t;
	for(i=0;i<t;i++){
		sum=a=b=c=0;
		cin>>n;
		for(j=0;j<n;j++){
			cin>>person[j].a>>person[j].b>>person[j].c;
			person[j].max=max(person[j].a,max(person[j].b,person[j].c));
		}
		stable_sort(person,person+n,cmp);
		for(j=0;j<n;j++){
			if(person[j].max==person[j].a && a<n/2){
				sum+=person[j].a;
				a++;
			}
			else if(person[j].max==person[j].b && b<n/2){
				sum+=person[j].b;
				b++;
			}
			else if(person[j].c>person[j].a && person[j].c >person[j].b && c<n/2){
				sum+=person[j].c;
				c++;
			}
			else{
				tmp=min(a,min(b,c));
				if(tmp==a){
					sum+=person[j].a;
					a++;
				}
				else if(tmp==b){
					sum+=person[j].b;
					b++;
				}
				else{
					sum+=person[j].c;
					c++;
				}
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
