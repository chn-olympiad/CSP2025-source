#include<bits/stdc++.h>
using namespace std;
struct d{
	int a,s,d,f;
}d[100005];
int p=0,o=0,u=0;
void aa(int a,int s,int d){
	if(a==max(max(a,s),d)){
		p++;
	}
	else if(s==max(max(a,s),d)){
		o++;
	}
	else{
		u++;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a,q=0;
	p=0;
	o=0;
	u=0;
	cin>>a;
	for(int i=0;i<a;i++){
		int s;
		cin>>s;
		for(int z=0;z<s;z++){
			cin>>d[z].a>>d[z].s>>d[z].d;
			if(p>=s/2){
			    d[z].a=0;
		    }
		    if(o>=s/2){
		    	d[z].s=0;
			}
			if(u>=s/2){
				d[z].d=0;
			}
			aa(d[z].a,d[z].s,d[z].d);
			q+=max(max(d[z].a,d[z].s),d[z].d);
		}
		cout<<q;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
