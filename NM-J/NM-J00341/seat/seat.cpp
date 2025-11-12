#include <bits/stdc++.h>
using namespace std;

int m,n;
int score[105];
int no;

int lie(int a,int b){
    if(a%b==0){
        return a/b;
    }else{
        return a/b+1;
    }
}
bool ou(int a){
    return !(a%2);
}
int hang(int a,int b,int c){
    if(ou(c)){
        return b-(a%b)+1;
    }else if(a%b==0){
    	return b;
	}else{
		return a%b;
	}
}
bool cmp(int x,int y){
	return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int s=m*n;
    for(int i=0;i<s;i++){
        cin>>score[i];
    }
    int yang=score[0];
    sort(score,score+s,cmp);
    for(int i=0;i<s;i++){
        if(score[i]==yang){
            no=i+1;
            break;
        }
    }
    cout<<lie(no,n)<<" "<<hang(no,n,lie(no,n));
    fclose(stdin);
    fclose(stdout);
    return 0;
}
