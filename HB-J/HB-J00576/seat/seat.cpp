#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[15][15];
int score[105];
int score_r;
int timed;
int now_pos;
int c,r;
int unqpl;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	timed = n*m;
	for(int i=1;i<=timed;i++){
		cin >> score[i];
	}
	score_r = score[1];
	sort(score+1,score+timed+1,cmp);
	for(int i=1;i<=timed;i++){
		if(score_r == score[i]){
			now_pos = i;
			i=timed+1;
			break;
		}
	}
	if(n==1 && m==1){
		cout << 1 << " " << 1;
	}else if(n==1){
		cout << now_pos << " " << 1;
	}else if(m==1){
		cout << 1 << " " << now_pos;
	}else{
		if(now_pos%n==0){
			r = now_pos/n;
		}else{
			r = (now_pos/n)+1;
		}
		if(r==1){
			cout << 1 << " " << now_pos;
		}else if(r%2 == 1){
			unqpl = (r-1)*n;
			c = now_pos-unqpl;
			cout << r << " " << c;
		}else{
			unqpl = (r-1)*n;
			c = now_pos-unqpl;
			c = n+1-c;
			cout << r << " " << c;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
