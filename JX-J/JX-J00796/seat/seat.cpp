#include<bits/stdc++.h>
using namespace std; 
int n,m,a[100005],t,c,r,pm,ans,cnt,cnt1=1;
int cmp(int x,int y){
	return x>=y;
}
int cc(int pm){
	for(int i=1;i<=10;i++){
	    if(pm-n>0){
		    pm-=n;
		    ans++;
	    }
	}
	return ans+=1;
}
int pp(int pm){
	if(pm<=n) return pm;
	else{
		for(int i=1;i<=10;i++){
		    if(pm-n>0){
			    cnt1++;
			    pm-=n;
			    cnt=pm;
			    if(cnt1%2==0)
			        cnt+=n/2;
		    }
	    }
	}
	return cnt;
}
int main(){
    freopen("seat.in","r",stdin); 
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
		cin>>a[i];
		t=a[1];
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(t==a[i]){
			pm=i;
			break;
		} 
		else continue;
	}
	if(pm==1) cout<<1<<" "<<1<<endl;
	else{
		c=cc(pm);
		r=pp(pm);
	}
	cout<<c<<" "<<r;
    fclose(stdin);
    fclose(stdout)
    return 0;
}
