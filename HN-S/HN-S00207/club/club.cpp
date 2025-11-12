#include<bits/stdc++.h>
using namespace std;
int t,n,ans,l[3];
struct people{
	int a[3],mx;
	bool f2;
}p[100000],q[100000];
/*
void mxxx(){
	for(int x=0;x<3;x++){
	for(int i=0;i<n-1;i++){
		for(int j=i;j<n-1;j++){
			if(q[j].a[x]<q[j+1].a[x]){
				swap(q[j].a[x],q[j+1].a[x]);
			}
		}
	}
	}
}
*/
void mxx(){
	int s[3]={0,0,0},x;
	for(int i=0;i<n;i++) s[p[i].mx]+=p[i].a[p[i].mx];
	x=max(s[0],max(s[1],s[2]));
	for(int i=0;i<3;i++){
	 if(x==s[i]){
	 	l[0]=i;
	 	break;
	 }
	}
	int a,b;
	for(int i=0;i<3;i++){
		if(i!=l[0]){
			a=i;
			for(int j=i;j<n;j++){
				if(j!=l[0]){
					b=j;
					break;
				}
			}
			break;
		}
	}
	if(max(s[a],s[b])==s[a]){
		l[1]=s[a];
		l[2]=s[b];
	}else{
		l[1]=s[b];
		l[2]=s[a];
	}
}

void mx(){
	/*
	
	for(int i=0;i<n;i++){//°´a[x]½µÐòÅÅÁÐ 
		for(int j=i;j<n-1;j++){
			 if(p[j].a[x]<p[j+1].a[x]){
			 	for(int i=0;i<3;i++) swap(p[j].a[i],p[j+1].a[i]);
			 }
		}
	}
	*/
	for(int i=0;i<n;i++){
		int x=max(p[i].a[0],max(p[i].a[1],p[i].a[2]));
		if(x==p[i].a[0]) p[i].mx=0;
		else if(x==p[i].a[1]) p[i].mx=1;
		else p[i].mx=2;
	}
}
void f(){
	for(int x=0;x<3;x++){
		int n2=0;
		for(int i=0;i<n;i++){
			if(p[i].mx==l[x]&&p[i].a[x]>=q[i].a[x/2-1]){//
				if(n2==n/2) break;
				if(p[i].f2==0){
					ans+=p[i].a[x];
					p[i].f2=1;
					n2++;
				}
				
			}
		}
		if(n2<n/2)
			l[x+3]=1;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>p[i].a[0]>>p[i].a[1]>>p[i].a[2];
			q[i].a[0]=p[i].a[0],q[i].a[1]=p[i].a[1],q[i].a[2]=p[i].a[2];
		}
		mx();
		mxx();
		f();
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
