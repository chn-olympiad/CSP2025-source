#include<cstdio>
#include<string>
using namespace std;
struct tstring{
	char data;
	tstring *next;
};
tstring *head,*p,*r;
struct nstring{
	int data;
	nstring *next;
};
nstring *head2,*p2,*r2;
void check(){
	p=head->next;
	head2=new nstring;
	head2->next=NULL;
	r2=head2;
	while(p!=NULL){
		if(p->data>='0'&&p->data<='9'){
			p2=new nstring;
			p2->data=p->data-'0';
			p2->next=NULL;
			r2->next=p2;
			r2=p2;
		}
		p=p->next;
	}
}
void re(){
	long back=0;
	int maxn=-1;
	bool br=false;
	while(br==false){
		maxn=-1;
		nstring *biggest;
		br=true;
		p2=head2->next;
		while(p2!=NULL){
			if(p2->data>maxn){
				maxn=p2->data;	
				biggest=p2;
			}
			if(p2->data!=-1)
			{
				br=false;
			}
			p2=p2->next;
		}
		back=back*10+biggest->data;
		biggest->data=-1;
	}
	back++;
	back/=10;
	printf("%ld",back);
}				
int main(){
	head=new tstring;
	head->next=NULL;
	r=head;
	char tmp='0';
	while(tmp!='\n'){
		scanf("%c",&tmp);
		p=new tstring;
		p->next=NULL;
		p->data=tmp;
		r->next=p;
		r=p;
	}
	
	check();
	re();
	return 0;
}
