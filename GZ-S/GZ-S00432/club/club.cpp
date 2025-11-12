//GZ-S00432 遵义市第四中学 邓俣宸 
#include<bits/stdc++.h>
using namespace std;
long long n,m,p1[100000],p2[100000],p3[100000],ma=-1;
bool o(int a,int b){
	return a>b;
}void dfs(int l,long long ans,int mm,int a,int b,int c){
	if(l==mm){
		if(a<=mm/2&&b<=mm/2&&c<=mm/2){
			ma=max(ma,ans);
		}return;
	}
	for(int i=0;i<3;i++){
		if(i==0){
			ans+=p1[l];
			a++;
			l++;
			dfs(l,ans,mm,a,b,c);
			a--;
			l--;
			ans-=p1[l];
		}else if(i==1){
			ans+=p2[l];
			b++;
			l++;
			dfs(l,ans,mm,a,b,c);
			b--;
			l--;
			ans-=p2[l];
		}else{
			ans+=p3[l];
			c++;
			l++;
			dfs(l,ans,mm,a,b,c);
			c--;
			l--;
			ans-=p3[l];
		}
	}return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>m;
		int o1=1,s1=0,o2=1,s2=0;
		for(int i=0;i<m;i++){
			cin>>p1[i]>>p2[i]>>p3[i];
			if(p2[i]!=0||p3[i]!=0)o1=0;
			if(p3[i]!=0)o2=0;
		}if(o1){
			sort(p1,p1+m,o);
			for(int i=0;i<m/2;i++){
				s1+=p1[i];
 			}cout<<s1<<endl;
		}else if(o2){
			int pp[100000],a=0,b=0,k;
			for(int i=0;i<m;i++){
				pp[i]=abs(p1[i]-p2[i]);
				if(p1[i]>p2[i]){
					a++;
					s2+=p1[i];
				}else{
					b++;
					s2+=p2[i];
				}
			}sort(pp,pp+m);
			if(a>m/2){
				k=a-m/2;
			}else if(b>m/2){
				k=b-m/2;
			}else{
				k=0;
			}for(int i=0;i<k;i++){
				s2-=pp[i];
			}cout<<s2<<endl;
		}else{
			ma=-1;
			dfs(0,0,m,0,0,0);
			cout<<ma<<endl;
		}		
	}
	return 0; 
}
