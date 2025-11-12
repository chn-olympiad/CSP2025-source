#include<fstream>
#include<string>
#include<algorithm>

std::fstream input("number.in");
std::fstream output("number.out");

int cnt{0};

int Cn(char c_){
    for(int i = 0; i < 10; i++){
        if(i==int(c_))
            return i;
    }
    return 0;
};

int main(){
    std::string mystring;
    int arr[mystring.size()]{};
    input>>mystring;

    for(int i = 0; i < mystring.size(); i++){
            arr[i] = Cn(mystring[i]);
    };
    std::sort(arr,arr+mystring.size());
    for(int i = 0; i < mystring.size(); i++)
        output<<arr[mystring.size()-i];
    return 0;
};