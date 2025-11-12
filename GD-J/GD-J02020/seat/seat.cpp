#include<iostream>
#include<algorithm>
using namespace std;

int n,m,len,_rank,line,col,tot;
bool flag,state;
struct Node{
	int value;
	bool tag;
} a[150];

bool cmp(Node a,Node b){
	return a.value>b.value;
}


void add(){
	for(int i=1;i<=n;i++){
		tot++;
		if(tot==_rank){
			flag=1;
			line=i;
		}
//		printf("col: %d line: %d rank: %d\n",col,i,tot);
	}	
}
	
void jian(){
	for(int i=n;i>=1;i--){
		tot++;
		if(tot==_rank){
			flag=1;
			line=i;
		}
//		printf("col: %d line: %d rank: %d\n",col,i,tot);
	}
}


void find(){
	flag=0;
	if(state){
		add();
	}else{
		jian();
	}
	
	if(flag){
		return;
	}else{
		state=!state;
		col++;
		find();
	}
}

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	a[1].tag=1;
	scanf("%d%d",&n,&m);
	len=n*m;
	for(int i=1;i<=len;i++){
		scanf("%d",&a[i].value);
	}
	
	sort(a+1,a+len+1,cmp);
	
	for(int i=1;i<=len;i++){
		if(a[i].tag){
			_rank=i;
		}
//		cout<<a[i].value<<" ";
	}
	
	state=1;
	col=1;
	find();
	
	printf("%d %d",col,line);
	
	return 0;
}
