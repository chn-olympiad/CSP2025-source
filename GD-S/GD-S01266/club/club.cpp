#include<bits/stdc++.h>
using namespace std;
int T;
int p1,p2,p3;
struct tian{
	int a,b,c;
}s[100005];
bool cmp(tian x,tian y){
	return x.a-max(x.b,x.c)>y.a-max(y.b,y.c);
}
bool cmp2(tian x,tian y){
	return x.b-max(x.a,x.c)>y.b-max(y.a,y.c);
}
bool cmp3(tian x,tian y){
	return x.c-max(x.a,x.b)>y.c-max(y.a,y.b);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T-- && T>=0){
		p1=0,p2=0,p3=0;
		int n,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			if(s[i].a==max(s[i].a,max(s[i].b,s[i].c))){
				sum+=s[i].a;
				p1++;
			}else if(s[i].b==max(s[i].a,max(s[i].b,s[i].c))){
				sum+=s[i].b;
				p2++;
			}else if(s[i].c==max(s[i].a,max(s[i].b,s[i].c))){
				sum+=s[i].c;
				p3++;
			}
		}
		//cout<<sum;
		while(p1>n/2){
			sort(s+1,s+1+n,cmp);
			if(p2+1<=n/2&&p3+1<=n/2){
				
				if(s[p1].b>s[p1].c){
					sum+=s[p1].b;
					sum-=s[p1].a;
					p2++;
				}else{
					sum+=s[p1].c;
					sum-=s[p1].a;
					p3++;
				} 
				p1--;
			}else if(p2+1<n/2){
				sum+=s[p1].b;
				sum-=s[p1].a;
				p2++;
				p1--;
			}else if(p3+1<n/2){
				sum+=s[p1].c;
				sum-=s[p1].a;
				p3++;
				p1--;
			}
		}
		while(p2>n/2){
			sort(s+1,s+1+n,cmp2);
			if(p1+1<=n/2&&p3+1<=n/2){
				if(s[p2].a>s[p2].c){
					sum+=s[p2].a;
					sum-=s[p2].b;
					p1++;
				}else{
					sum+=s[p2].c;
					sum-=s[p2].b;
					p3++;
				} 
				p2--;
			}else if(p1+1<n/2){
				sum+=s[p2].a;
				sum-=s[p2].b;
				p1++;
				p2--;
			}else if(p3+1<n/2){
				sum+=s[p2].c;
				sum-=s[p2].b;
				p3++;
				p2--;
			}
		}
		while(p3>n/2){
			sort(s+1,s+1+n,cmp3);
			if(p1+1<=n/2&&p2+1<=n/2){
				if(s[p3].a>s[p3].b){
					sum+=s[p3].a;
					sum-=s[p3].c;
					p1++;
				}else{
					sum+=s[p3].b;
					sum-=s[p3].c;
					p2++;
				} 
				p3--;
			}else if(p1+1<n/2){
				sum+=s[p3].a;
				sum-=s[p3].c;
				p1++;
				p3--;
			}else if(p2+1<n/2){
				sum+=s[p3].b;
				sum-=s[p3].c;
				p2++;
				p3--;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

