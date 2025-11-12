#include<bits/stdc++.h>
using namespace std;
int n,t,ansa,d,ans3,ans4;
struct node{
	int a,b,c;
};

node q[200010]={};
node qa[10000]={};
node qb[10000]={};
node qc[10000]={};

bool cmpa(node x,node y){
	return x.a>y.a;
}

bool cmpb(node x,node y){
	return x.b>y.b;
}

bool cmpc(node x,node y){
	return x.c>y.c;
}

void solve(int a1,int b1,int c1,int num){
if(num==1){
	int m=max(b1,c1);
	if(m==b1){
		sort(qb+1,qb+d,cmpb);
			if(qb[d-1].b<b1&&d!=1){
				swap(qb[d-1].a,a1);
				swap(qb[d-1].b,b1);
				swap(qb[d-1].c,c1);
			}
		if(d>n/2){
				solve(a1,b1,c1,2); 	
		}
		else{
			qb[d].a=a1;
			qb[d].b=b1;
			qb[d].c=c1;
			d++;
		}
	}
	else{
		sort(qc+1,qc+ans3,cmpc);
			if(qc[ans3-1].c<c1&&ans3!=1){
				swap(qc[ans3-1].a,a1);
				swap(qc[ans3-1].b,b1);
				swap(qc[ans3-1].c,c1);
			}
		if(ans3>n/2){
				solve(a1,b1,c1,3); 
				
		}
		else{
			qc[ans3].a=a1;
			qc[ans3].b=b1;
			qc[ans3].c=c1;
			ans3++;
		}
	}
}
else if(num==2){
	int m=max(a1,c1);
	if(m==a1){
		sort(qa+1,qa+ansa,cmpa);
		if(qa[ansa-1].a<a1&&ansa!=1){
			swap(qa[ansa-1].a,a1);
			swap(qa[ansa-1].b,b1);
			swap(qa[ansa-1].c,c1);
		}
		if(ansa>n/2){
				solve(a1,b1,c1,1); 
				
			}
		else{
			qa[d].a=a1;
			qa[d].b=b1;
			qa[d].c=c1;
			ansa++;
		}
	}
	else{
		sort(qc+1,qc+ans3,cmpc);
			if(qc[ans3-1].c<c1&&ans3!=1){
				swap(qc[ans3-1].a,a1);
				swap(qc[ans3-1].b,b1);
				swap(qc[ans3-1].c,c1);
			}
		if(ans3>n/2){
				solve(a1,b1,c1,3); 
	
		}
		else{
			qc[ans3].a=a1;
			qc[ans3].b=b1;
			qc[ans3].c=c1;
			ans3++;
		}
	}
}

else{
	int m=max(a1,b1);
	if(m==a1){
		sort(qa+1,qa+ansa,cmpa);
			if(qa[ansa-1].a<a1&&ansa!=1){
				swap(qa[ansa-1].a,a1);
				swap(qa[ansa-1].b,b1);
				swap(qa[ansa-1].c,c1);
			}
		if(ansa>n/2){
				solve(a1,b1,c1,1); 
		
			}
		else{
			qa[d].a=a1;
			qa[d].b=b1;
			qa[d].c=c1;
			ansa++;
		}
	}
	else{
		sort(qb+1,qb+d,cmpb);
			if(qb[d-1].b<b1&&d!=1){
				swap(qb[d-1].a,a1);
				swap(qb[d-1].b,b1);
				swap(qb[d-1].c,c1);
			}
		if(d>n/2){
			solve(a1,b1,c1,2); 
		
			}
		else{
			qb[d].a=a1;
			qb[d].b=b1;
			qb[d].c=c1;
			d++;
		}
	}
	}
}




void f(){
//	cout<<1;
	int sum=0;
	memset(qa,0,sizeof(qa));
	memset(qb,0,sizeof(qa));
	memset(qc,0,sizeof(qa));
	ansa=1;
	d=1;
	ans3=1;
	ans4=1; 
	cin>>n;
	for(int i=1;i<=n;i++){
		int a1,b1,c1;
		cin>>a1>>b1>>c1;
		int m=max(a1,max(b1,c1));
		if(m==a1){
			sort(qa+1,qa+ansa,cmpa);
			if(qa[ansa-1].a<a1&&ansa!=1){
				swap(qa[ansa-1].a,a1);
				swap(qa[ansa-1].b,b1);
				swap(qa[ansa-1].c,c1);
			}
			//	cout<<1;
			if(ansa>n/2){
				solve(a1,b1,c1,1); 
				continue;
			}
			qa[ansa].a=a1;
			qa[ansa].b=b1;
			qa[ansa].c=c1;
			ansa+=1;
		}
		else if(m==b1){
			sort(qb+1,qb+d,cmpb);
			if(qb[d-1].b<b1&&d!=1){
				swap(qb[d-1].a,a1);
				swap(qb[d-1].b,b1);
				swap(qb[d-1].c,c1);
			}
			if(d>n/2){
				solve(a1,b1,c1,2); 
				continue;
			}
			qb[d].a=a1;
			qb[d].b=b1;
			qb[d].c=c1;
			d++;
		}
		else if(m==c1){
			sort(qc+1,qc+ans3,cmpc);
			if(qc[ans3-1].c<c1&&ans3!=1){
				swap(qc[ans3-1].a,a1);
				swap(qc[ans3-1].b,b1);
				swap(qc[ans3-1].c,c1);
			}
			if(ans3>n/2){
				solve(a1,b1,c1,3); 
				continue;
			}
			qc[ans3].a=a1;
			qc[ans3].b=b1;
			qc[ans3].c=c1;
			ans3++;
		}
			
	}
	sort(qa+1,qa+ansa,cmpa);
	sort(qb+1,qb+d,cmpb);
	sort(qc+1,qc+ans3,cmpc);
//	cout<<ansa<<" "<<d<<" "<<ans3;
	for(int i=1;i<=ansa;i++){
		sum+=qa[i].a;
	}
	for(int i=1;i<=d;i++){
		sum+=qb[i].b;
	}
	for(int i=1;i<=ans3;i++){
		sum+=qc[i].c;
	}
	cout<<sum<<endl;
//	cout<<1;
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		f();
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
