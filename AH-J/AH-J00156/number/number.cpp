#include <iostream>
#include <string>
using namespace std;

string s;
int number_count[10];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(char i:s){
        if(i>='0'&&i<='9') number_count[i-'0']++;
    }
    for(int i=9;i>=0;i--){
        while(number_count[i]--){
            cout<<i;
        }
    }
    return 0;
}

/*
样例4的数据有些过于离谱了，把gedit干未响应
试一下别的文本编辑器

最新数据：emacs的GUI模式也炸了
时间不多了，去T2
*/