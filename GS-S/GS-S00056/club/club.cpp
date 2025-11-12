#include<bits/stdc++.h> 
using namespace std;
int t,n[10],ans;
struct club{
	int a,b,c,d=0;
}cc[100005];
struct c1{
	int x,s;
}a1[100005];
struct c2{
	int x,s;
}b1[100005];
bool dtl1(c1 o1,c1 o2){
	return o1.s>=o2.s;
}
bool dtl2(c2 o1,c2 o2){
	return o1.s>=o2.s;
}
void w1(int k){
	sort(a1,a1+k,dtl1);
	for(int i=0;i<k/2;i++)
		ans+=a1[i].s;
	cout<<ans;
	ans=0;
}
void w2(int k){
	sort(a1,a1+k,dtl1);
	sort(b1,b1+k,dtl2);
	int mm=k/2;
	int at=0,bt=0;
	while(at<mm||bt<mm){
		if(a1[at].x!=b1[bt].x){
		if(at<mm){
			if(cc[a1[at].x].d==0){
			ans+=a1[at].s;
			cc[a1[at].x].d=1;
			at++;
		}
			else
			at++;
		}
		if(bt<mm){
			if(cc[b1[bt].x].d==0){
			ans+=b1[bt].s;
			cc[b1[bt].x].d=1;
			bt++;
		}
		else
		bt++;
		}
		}
		else{
			if((a1[at].s+b1[bt+1].s)>(b1[bt].s+a1[at+1].s)){
				cc[a1[at].x].d=1;
				ans+=a1[at].s;
				at++;
			}
			else if((a1[at].s+b1[bt+1].s)<=(b1[bt].s+a1[at+1].s)){
				cc[a1[at].x].d=1;
				ans+=b1[bt].s;
				bt++;
			}
		}
		if(at>=mm&&bt<mm){
			for(int i=bt;i<mm;i++)
				ans+=b1[i].s;
		}
		else if(bt>=mm&&at<mm){
			for(int i=at;i<mm;i++)
				ans+=a1[i].s;
		}
		}
	cout<<ans;
	ans=0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int m[10];
	for(int i=0;i<t;i++){
		cin>>n[i];
		m[i]=n[i]/2;
		for(int j=0;j<n[i];j++){
			cin>>cc[j].a>>cc[j].b>>cc[j].c;
			a1[j].x=j,a1[j].s=cc[j].a;
			b1[j].x=j,b1[j].s=cc[j].b;
		}
		if(b1[0].s==0)
		w1(n[i]);
		else
		w2(n[i]);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
